#include "muChContikiMAC.h"
#include "packet_m.h"
#include "mac.h"
#include "radio.h"

#ifndef  DEBUG
#define DEBUG 1
#endif

namespace wsn_energy {

Define_Module(muChContikiMAC);

void muChContikiMAC::initialize() {
    RDCdriver::initialize();
    this->phase = FREE_PHASE;

    // start channel check timer (only if RDC)
    selfTimer(0, RDC_PERIODICAL_MAJOR_CHECK);
}

void muChContikiMAC::processLowerLayerMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case DATA: /* Data */
    {
        this->receiveFrame(check_and_cast<Frame*>(packet));
        break;
    } /* Data */

    case RESULT:
        /* Result */
    {
        switch (check_and_cast<Result*>(packet)->getNote()) {
        case PHY_TX_OK: /* callback after transmitting */
        {
            if (isSentACK) {
                isSentACK = false;
            } else if (phaseTimeOut->isScheduled()) {
                if (this->bufferRDC->getAckRequired()) {
                    // listen to ACK
                    on();

                    // refresh CCA in one turn
                    ccaInOneTurn = CCA_TRANS_MAX;

                    // check time-out
                    selfTimer(INTER_FRAME_INTERVAL, RDC_BEGIN_TRANS_TURN);
                } else {
                    // sleep
                    off();

                    // refresh CCA in one turn
                    ccaInOneTurn = CCA_TRANS_MAX;

                    // check-time out
                    selfTimer(INTER_FRAME_INTERVAL, RDC_BEGIN_TRANS_TURN);
                }
            }
            break;
        }/* callback after transmitting */

        case PHY_TX_ERR: /* Internal error */
        {
            // stop transmission
            // inform fatal
            quitRDCtransmissionPhase(RDC_SEND_FATAL);

            break;
        }/* Internal error */

        default:
            delete packet;
            ev << "Unknown result" << endl;
            break;
        }
        delete packet; // done result
        break;
    } /* Result */

    default:
        delete packet;
        ev << "Unknown kind" << endl;
        break;
    }
}

void muChContikiMAC::selfProcess(cPacket* packet) {
    switch (packet->getKind()) {
    case COMMAND: /* Command */
    {
        switch (check_and_cast<Command*>(packet)->getNote()) {
        case RDC_CCA_REQUEST: /* check cca */
        {
            int numChannels = getModuleByPath("^.^")->par("numChannels");
            if (numChannels < 1)
                numChannels = 1;
            if (phase == CHECKING_PHASE) {
                // Listening
                freqChannel = nextChannel;
                nextChannel = intuniform(26 - (numChannels - 1), 26);
            } else {
                // Sending
                freqChannel = preferredFreqChannel;
                preferredFreqChannel = 0;
                if (freqChannel == 0) {
                    freqChannel = intuniform(26 - (numChannels - 1), 26);
                }
            }
//            if (preferredFreqChannel != 0) {
//                if (DEBUG)
//                    std::cout << "[RDC] Try to use preferred channel"
//                            << std::endl;
//                freqChannel = preferredFreqChannel;
//                preferredFreqChannel = 0;
//            } else {
//            int temp = freqChannel;
//            freqChannel = intuniform(23, 26);
//            if (freqChannel == temp) {
//                freqChannel = intuniform(23, 26);
//            }
//            }
            if (DEBUG) {
                std::cout << "[RDC] Freq: " << this->freqChannel << endl;
            }
            sendCommand(RDC_SWITCH_FREQ_CHANNEL | (freqChannel << 8));
            sendCommand(RDC_CCA_REQUEST);

            if (DEBUG)
                std::cout << getFullPath() << "cca: " << ccaType << " @ "
                        << simTime().dbl() << endl;

            // need to consider overlap CCA ???
            cancelEvent(ccaResult);
            scheduleAt(simTime().dbl() + CCA_CHECK_TIME, ccaResult);

            delete packet;

            break;
        } /* check cca */

        case RDC_CCA_RESULT: /* check cca result */
        {
            if (cca()) /* Channel busy*/
            {
                if (DEBUG)
                    ev << "Channel is busy" << endl;

                switch (phase) {
                case TRANSMITTING_PHASE: /* CCA on transmitting */
                {
                    // distinguish MAC CCA and RDC CCA
                    switch (ccaType) {
                    case MAC_CCA: /* MAC CCA */
                    {
                        sendResult(CHANNEL_BUSY);

                        // turn off after CCA
                        off();

                        break;
                    } /* MAC CCA */

                    case RDC_TRANS_CCA: // cca on trans
                    {
                        ccaInOneTurn--;

                        // is reaching maxium number of CCA
                        if (phaseTimeOut->isScheduled()) {
                            if (ccaInOneTurn < 0) {
                                // stop transmission phase
                                // inform busy channel
                                quitRDCtransmissionPhase(RDC_SEND_COL);
                            } else {
                                // turn off radio
                                off();

                                // wait sleep time and perform another CCA
                                selfTimer(CCA_SLEEP_TIME, RDC_BEGIN_TRANS_TURN);
                            }
                        }
                        break;
                    }

                    case RDC_CHECK_CCA: // cca on check
                    {
                        break;
                    } /* RDC CCA */
                    }

                    break;
                } /* CCA on transmitting */

                case CHECKING_PHASE: /* CCA on checking */
                {
                    // nulltify following cca
                    ccaCounter = 0;

                    // listen for a period of time
                    scheduleAt(simTime().dbl() + LISTEN_AFTER_DETECT,
                            ccaTimeOut);

                    // if has pending phase, wait for cca time out cancel it

                    break;
                } /* CCA on checking*/

                case FREE_PHASE: // ???
                {
                    break;
                }

                }
            } /* Channel busy */

            /* Channel clear */
            else {
                if (DEBUG)
                    ev << "Channel is clear" << endl;

                switch (phase) {
                case TRANSMITTING_PHASE: /* CCA on transmitting */
                {
                    // distingush MAC CCA and RDC CCA
                    switch (ccaType) {
                    case MAC_CCA: /* MAC CCA */
                    {
                        sendResult(CHANNEL_CLEAR);

                        // Turn off after CCA
                        off();

                        break;
                    } /* MAC CCA */

                    case RDC_TRANS_CCA: // cca on trans
                    {
                        // reset cca in one turn
                        ccaInOneTurn = CCA_TRANS_MAX;

                        // transmitting
                        sendFrame();

                        break;
                    }

                    case RDC_CHECK_CCA: // rdc check on transmitting ???
                    {
                        break;
                    } /* RDC CCA */
                    }

                    break;
                } /* CCA on transmitting */

                case CHECKING_PHASE: /* CCA on checking*/
                {
                    // decrease cca counter
                    ccaCounter--;

                    // has pending transmission phase
                    if (isHavingPendingTransmission) {
                        // enter transmission phase
                        enterMACtransmissonPhase();
                    }
                    // consider if last cca
                    else if (ccaCounter == 0) {
                        // release checking phase
                        phase = FREE_PHASE;

                        // not seen
                        off();
                    } else {
                        // schedule next cca
                        selfTimer(CCA_SLEEP_TIME, RDC_PERIODICAL_MINOR_CHECK);

                        // not seen
                        off();
                    }

                    break;
                } /* CCA on checking*/

                case FREE_PHASE: // free phase
                {
                    break;
                }
                }
            } /* Channel clear */

            // do not delete cca request for later reuse

            break;
        } /* check cca result */

        case RDC_PERIODICAL_MINOR_CHECK: /* minor channel check */
        {
            if (!ccaTimeOut->isScheduled() && !ccaResult->isScheduled() && !isHavingPendingTransmission && phase == CHECKING_PHASE) {
                // begin CCA indicator
                ccaCounter--;
                ccaType = RDC_CHECK_CCA;
                selfTimer(0, RDC_CCA_REQUEST);
            } else {
                enterMACtransmissonPhase();
            }

            delete packet; // done command

            break;
        } /* minor channel check */

        case RDC_PERIODICAL_MAJOR_CHECK: /* major channel check */
        {
            // schedule next checking phase
            selfTimer(CHANNEL_CHECK_INTERVAL, RDC_PERIODICAL_MAJOR_CHECK);

            switch (phase) {
            case TRANSMITTING_PHASE: /* schedule but not perform checking phase */
            {
                break;
            } /* schedule but not perform checking phase */

            case CHECKING_PHASE: /* is on checking phase */
            {
                break;
            } /* is on checking phase */

            case FREE_PHASE: /* begin a checking phase */
            {
                if (isHavingPendingTransmission) {
                    enterMACtransmissonPhase();
                } else {
                    // acquire checking phase
                    phase = CHECKING_PHASE;

                    // reset cca counter
                    ccaCounter = CCA_COUNT_MAX;

                    // begin CCA indicator
                    selfTimer(0, RDC_PERIODICAL_MINOR_CHECK);
                }

                break;
            } /* begin a checking phase*/
            }

            delete packet; // done command

            break;
        } /* major channel check*/

        case RDC_BEGIN_TRANS_TURN:
            /* begin a transmission turn */
        {
            enterRDCtransmissionPhase();

            delete packet; // done command

            break;
        } /* begin a transmission turn */

        case RDC_PHASE_TIME_OUT:
            /* phase time out */
        {
            if (bufferRDC->getAckRequired()) // if unicast + NO ACK
            {
                // stop transmission
                // inform failure
                quitRDCtransmissionPhase(RDC_SEND_NO_ACK);
            } else // broadcast is always success
            {
                // stop transmission
                // inform success
                quitRDCtransmissionPhase(RDC_SEND_OK);
            }

            // do not delete phase time out for later reuse

            break;
        } /* phase time out  */

        case RDC_CCA_TIME_OUT:
            /* cca time out */
        {
            // time out
            if (phase == CHECKING_PHASE)
                phase = FREE_PHASE;

            // turn off radio
            off();

            // if pending, ready for next phase
            if (isHavingPendingTransmission)
                enterMACtransmissonPhase();

            // do not delete cca time out for later reuse

            break;
        }/* cca time out */

        default:
            ev << "Unknown command" << endl;
            delete packet; // done command
            break;
        }
        break;
    } /* Command */

    default:
        delete packet;
        ev << "Unknown kind" << endl;
        delete packet;
        break;
    }
}

void muChContikiMAC::enterMACtransmissonPhase() {
    if (isHavingPendingTransmission) {
        if (DEBUG)
            ev << "RDC: Enter transmission phase" << endl;

        // release pending
        isHavingPendingTransmission = false;

        // acquire transmitting phase
        phase = TRANSMITTING_PHASE;

        sendResult(RDC_READY_TRANS_PHASE);

        cancelEvent(ccaTimeOut);
        cancelEvent(ccaResult);
    }
}

void muChContikiMAC::quitMACtransmissonPhase() {
    // release lock
    phase = FREE_PHASE;

    cancelEvent(phaseTimeOut);
    cancelEvent(ccaTimeOut);
    cancelEvent(ccaResult);

    // clear last buffer
    if (this->bufferRDC != NULL) {
        delete this->bufferRDC;
        this->bufferRDC = NULL;
    }
}

void muChContikiMAC::enterRDCtransmissionPhase() {
    if (phaseTimeOut->isScheduled()) // still not time-out
    {
        cancelEvent(ccaResult);
        cancelEvent(ccaTimeOut);

        // RDC CCA in order to make sure channel is clear
        ccaType = RDC_TRANS_CCA;
        selfTimer(0, RDC_CCA_REQUEST);
    }
}

void muChContikiMAC::quitRDCtransmissionPhase(int result) {
    // stop transmission phase
    if (DEBUG)
        ev << "RDC: Quit 1 turn in transmission phase" << endl;

    // stop timeout transmission phase
    cancelEvent(phaseTimeOut);
    cancelEvent(ccaResult);
    cancelEvent(ccaTimeOut);

    // turn off radio, just in case
    off();

    sendResult(result);
}

/* command from MAC */
void muChContikiMAC::beginTransmitting(int command) {
    switch (command) {
    case MAC_CCA_REQUEST: /* request CCA */
    {
        ccaType = MAC_CCA;
        selfTimer(0, RDC_CCA_REQUEST);
        break;
    } /* request CCA */

    case MAC_ASK_SEND_FRAME: /* register a transmission phase */
    {
        // does not aquire transmission phase at this stage
        if (this->phase == FREE_PHASE) // is free
        {
            isHavingPendingTransmission = true;
            enterMACtransmissonPhase();
        }
        // cancel if on checking cca
        else if (ccaResult->isScheduled()) {
            cancelEvent(ccaResult);
            isHavingPendingTransmission = true;
            enterMACtransmissonPhase();
        }
        // place holder in case of cca
        else if (ccaTimeOut->isScheduled()) {
            isHavingPendingTransmission = true;
        } else {
            std::cout << "unhandled phase " << phase << endl;
        }

        break;
    } /* register a transmission phase */

    case MAC_END_SEND_FRAME: /* end a transmission phase */
    {
        quitMACtransmissonPhase();

        break;
    }/* end a transmission phase */

    case MAC_IGNITE_RDC: /* begin a turn in a transmission phase */
    {
        // acquire phase lock (if possible)
        double phaseLock = 0;

        // reset number of cca
        ccaInOneTurn = 0;

        // create time out
        scheduleAt(simTime().dbl() + MAX_PHASE_STROBE, phaseTimeOut);

        // phase lock wait
        selfTimer(phaseLock, RDC_BEGIN_TRANS_TURN);

        break;
    } /* begin a transmission phase */

    default:
        ev << "Unknown command" << endl;
        break;
    }
}
void muChContikiMAC::sendFrame() {
    if (phase == TRANSMITTING_PHASE
            && phaseTimeOut->isScheduled() && bufferRDC != NULL) {
        bufferRDC->setAckRequired(true);
        sendMessageToLower(bufferRDC->dup());
        sendCommand(RDC_TRANSMIT);
    }
}

/* send packet */
void muChContikiMAC::transmitFrame() {
    return;
}

/* receive success from PHY */
void muChContikiMAC::receiveFrame(Frame* packet) {
    if (phase == CHECKING_PHASE)
        phase = FREE_PHASE;

    // if pending, ready for next phase
    if (isHavingPendingTransmission)
        enterMACtransmissonPhase();

    cancelEvent(ccaTimeOut);

    // consider is ACK
    if (check_and_cast<Frame*>(packet)->getHeaderLength() == ACK_LENGTH) {
        // only consider in case of unicast transmission
        if (bufferRDC != NULL) {
            if (bufferRDC->getAckRequired() && !cca()) {
                // not itself ACK / false positive
                if (check_and_cast<FrameACK*>(packet)->getDataSequenceNumber()
                        != (check_and_cast<MACdriver*>(getModuleByPath("^.mac"))->sequenceNumber)) {
                    // dismiss
                } else {
                    // stop transmission if still in transmission phase
                    // inform success
                    preferredFreqChannel = packet->getReserved();
                    if (DEBUG)
                        std::cout << "[ACK] freqChannel = " << freqChannel
                                << std::endl;
                    if (phaseTimeOut->isScheduled())
                        quitRDCtransmissionPhase(RDC_SEND_OK);
                }

                // remember phase lock (minus ack transmission time, minus reception time -> wake up time)
            }
        }

        // delete ack
        delete packet;
    } else {
        // receive DATA in ACK period

        // receive DATA in checking period

        // turn off radio
        if (!ccaResult->isScheduled() && phase != TRANSMITTING_PHASE)
            off();

        switch (check_and_cast<Frame*>(packet)->getFrameType())
        /* Frame type */
        {
        case FRAME_DATA: /* frame data */
        {
            if (getModuleByPath("^.^")->par("usingHDC").boolValue()) {
                // compress using HC01

                FrameDataCompressed* frame =
                        check_and_cast<FrameDataCompressed*>(packet);

                // consider right address
                int destinationMacAddress = frame->getDestinationMacAddress();
                int sourceMacAddress = frame->getSourceMacAddress();

                // unicast + wrong MAC address
                if (destinationMacAddress != 0
                        && destinationMacAddress
                                != this->getParentModule()->getModuleByPath(
                                        ".mac")->getId()) {
                    // lost packet (not broadcast and wrong mac address) dismiss
                    delete packet;
                } else {
                    if (check_and_cast<RadioDriver*>(getModuleByPath("^.radio"))->incomingSignal
                            <= 1&& check_and_cast<RadioDriver*>(getModuleByPath("^.radio"))->status != POWER_DOWN) {
                        // check ACK required
                        if (frame->getAckRequired()) {
                            // send ACK
                            FrameACK* ack = new FrameACK;
                            ack->setKind(DATA);
                            ack->setByteLength(ACK_LENGTH);
                            ack->setReserved(nextChannel);
                            ack->setDataSequenceNumber(
                                    frame->getDataSequenceNumber());

                            // Simulate AUTO-ACK
                            Raw* ackRaw = new Raw;
                            ackRaw->setKind(DATA);
                            ackRaw->setByteLength(ackRaw->getHeaderLength());

                            ackRaw->encapsulate(ack);

                            sendDirect(ackRaw,
                                    simulation.getModule(sourceMacAddress)->getModuleByPath(
                                            "^.radio")->gate("radioIn"));

                            //                        isJustSendACK = true;
                        }

                        // consider sequence number (duplicate)
                        bool isFound = false;

                        // search through neighbor list
                        for (std::list<Neighbor*>::iterator it =
                                this->neighbors.begin();
                                it != this->neighbors.end(); it++) {
                            // if neighbor in ARP table
                            if ((*it)->senderID == sourceMacAddress) {
                                isFound = true;

                                if ((*it)->sequence
                                        < frame->getDataSequenceNumber()) {
                                    // not duplicated, send to upper
                                    ((*it))->sequence =
                                            frame->getDataSequenceNumber();
                                    sendMessageToUpper(frame);
                                } else {
                                    // duplicated message, dismiss
                                    delete frame;
                                }

                                break;
                            }
                        }

                        // if neighbor not in MAC-IP table, create new and send to upper
                        if (!isFound) {
                            Neighbor* neighbor = new Neighbor;
                            neighbor->senderID = sourceMacAddress;
                            neighbor->sequence = frame->getDataSequenceNumber();

                            this->neighbors.push_back(neighbor);

                            sendMessageToUpper(frame);
                        }
                    } else {
                        delete frame;
                    }
                }
            }
            // Normal mode
            else {
                FrameDataStandard* frame = check_and_cast<FrameDataStandard*>(
                        packet);

                // consider right address
                int destinationMacAddress = frame->getDestinationMacAddress();
                int sourceMacAddress = frame->getSourceMacAddress();

                // unicast + wrong MAC address
                if (destinationMacAddress != 0
                        && destinationMacAddress
                                != this->getParentModule()->getModuleByPath(
                                        ".mac")->getId()) {
                    // lost packet (not broadcast and wrong mac address) dismiss
                    delete packet;
                } else {
                    // check ACK required
                    if (frame->getAckRequired()) {
                        // send ACK
                        FrameACK* ack = new FrameACK;
                        ack->setKind(DATA);
                        ack->setByteLength(ack->getHeaderLength());
                        ack->setDataSequenceNumber(
                                frame->getDataSequenceNumber());

                        // Simulate AUTO-ACK
                        Raw* ackRaw = new Raw;
                        ackRaw->setKind(DATA);
                        ackRaw->setByteLength(ackRaw->getHeaderLength());

                        ackRaw->encapsulate(ack);

                        sendDirect(ackRaw,
                                simulation.getModule(sourceMacAddress)->getModuleByPath(
                                        "^.radio")->gate("radioIn"));

                        //                        isJustSendACK = true;
                    }

                    // consider sequence number (duplicate)
                    bool isFound = false;

                    // search through neighbor list
                    for (std::list<Neighbor*>::iterator it =
                            this->neighbors.begin();
                            it != this->neighbors.end(); it++) {
                        // if neighbor in ARP table
                        if ((*it)->senderID == sourceMacAddress) {
                            isFound = true;

                            if ((*it)->sequence
                                    < frame->getDataSequenceNumber()) {
                                // not duplicated, send to upper
                                ((*it))->sequence =
                                        frame->getDataSequenceNumber();

                                sendMessageToUpper(frame);
                            } else {
                                // duplicated message, dismiss
                                delete packet;
                            }

                            break;
                        }
                    }

                    // if neighbor not in MAC-IP table, create new and send to upper
                    if (!isFound) {
                        Neighbor* neighbor = new Neighbor;
                        neighbor->senderID = sourceMacAddress;
                        neighbor->sequence = frame->getDataSequenceNumber();

                        this->neighbors.push_back(neighbor);

                        sendMessageToUpper(frame);
                    }
                }
            }

            break;
        } /* frame data */

        } /* Frame type */
    }
    return;
}
} /* namespace wsn_energy */
