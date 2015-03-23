/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to csma.h
 */

#include "csma.h"
#include "packet_m.h"

#define BACKOFF_PERIOD                0.0032 // second, 20 symbols
#define MAC_MIN_BE                    3 // min backoff exponent
#define MAC_MAX_BE                    5 // max backoff exponent
#define MAX_BACKOFF_TRANSMISSION      3 // 3 tries per frame

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

Define_Module(csma);

void csma::deferPacket() {
    /* dismiss + announce failure duty */
    if (bufferMAC->getNumberTransmission() > MAX_BACKOFF_TRANSMISSION) {
        // consider IFS
        if (this->bufferMAC->getByteLength() > MAX_SIFS_FRAME_SIZE)
            selfTimer(LIFS, MAC_EXPIRE_IFS);
        else
            selfTimer(SIFS, MAC_EXPIRE_IFS);

//    sendResult(MAC_RELIABLE);

        endMACphase();
    }
    /* unslotted csma */
    else {
        double backoff;
        int backoff_transmission, backoff_exponent;

        backoff_exponent =
        MAC_MAX_BE < bufferMAC->getNumberTransmission() + MAC_MIN_BE ?
                MAC_MAX_BE : bufferMAC->getNumberTransmission() + MAC_MIN_BE; // truncate

        backoff_transmission = 1 << backoff_exponent;

        int backoffUnit;

        if (getModuleByPath("^.^")->par("rand").doubleValue() == 0)
            backoffUnit = (rand() % (backoff_transmission));
        else if (getModuleByPath("^.^")->par("rand").doubleValue() == 1)
            backoffUnit = (intuniform(0, backoff_transmission));

        // create unsynchronization
        backoff = backoffUnit * BACKOFF_PERIOD
                + intuniform(0, 1000) / 1000000000.0;

        if (DEBUG)
            std::cout << "Random " << backoff_transmission << "/" << backoffUnit
                    << "/" << backoff << endl;

        bufferMAC->setNumberTransmission(
                bufferMAC->getNumberTransmission() + 1);

        /* request to perform CCA */
        selfTimer(backoff, MAC_CCA_REQUEST);
    }
}

void csma::processSelfMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case COMMAND: /* Command */
    {
        switch (check_and_cast<Command*>(packet)->getNote()) {
        case MAC_CCA_REQUEST: /* perform CCA*/
        {
            sendCommand(MAC_CCA_REQUEST);
            break;
        } /* perform CCA */

        case MAC_EXPIRE_IFS: /* expire IFS */
        {
            // clear buffer
            if (this->bufferMAC != NULL) {
                delete this->bufferMAC;
                this->bufferMAC = NULL;
            }

//            if (DEBUG)
//                std::cout << this->getFullPath() << " end mac "
//                        << simTime().dbl() << " "
//                        << check_and_cast<IPv6*>(getModuleByPath("^.net"))->ipPacketQueue.size()
//                        << endl;

            sendResult(MAC_FINISH_PHASE);

            break;
        } /* expire IFS*/

        default:
            if (DEBUG)
                std::cout << "Unknown command" << endl;
            break;
        }
        break;
        /* Command */
    }

    default:
        if (DEBUG)
            std::cout << "Unknown kind" << endl;
        break;
    }

    delete packet;
}

void csma::processUpperLayerMessage(cPacket* packet) {
    /* only process data packet */
    MACdriver::encap(packet);

    // prepare a MAC transmission phase
    sendMessageToLower(bufferMAC->dup());
    sendCommand(MAC_ASK_SEND_FRAME);

    if (DEBUG)
        std::cout << this->getFullPath() << " begin mac" << simTime().dbl()
                << endl;
}

void csma::processLowerLayerMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case DATA: /* Data */
    {
        // received message
        receiveFrame(check_and_cast<Frame*>(packet));
        break;
    } /* Data */

    case RESULT: /* Result */
    {
        switch (check_and_cast<Result*>(packet)->getNote()) {
        case CHANNEL_CLEAR: /* channel is clear */
        {
            // ready to enter a RDC phase
            igniteRDCphase();

            break;
        } /* channel is clear */

        case CHANNEL_BUSY: /* channel is busy */
        {
            // not ready enter a RDC phase
            deferPacket();

            break;
        } /* channel is busy */

        case RDC_READY_TRANS_PHASE: /* successfully set up a transmission phase */
        {
            // success enter a transmission phase, start by deferring packet
            deferPacket();

            break;
        }/* successfully set up a transmission phase */

        case RDC_SEND_OK: /* successful transmitting and receive ACK if needed */
        {
            // end MAC phase
            endMACphase();

            // consider IFS
            if (bufferMAC->getByteLength() > MAX_SIFS_FRAME_SIZE)
                selfTimer(LIFS, MAC_EXPIRE_IFS);
            else
                selfTimer(SIFS, MAC_EXPIRE_IFS);

            break;
        } /* successful transmitting and receive ACK if needed */

        case RDC_SEND_NO_ACK: /* unicast but no ACK received */
        {
            // no ack is considered dead neighbor
            if (this->bufferMAC->getNumberTransmission() > 3) {
                // no dead ???
                sendResult(MAC_SEND_DEAD_NEIGHBOR);

                //std::cout << "NO ACK !!!" << endl;

                // end MAC phase
                endMACphase();

                // consider IFS
                if (bufferMAC->getByteLength() > MAX_SIFS_FRAME_SIZE)
                    selfTimer(LIFS, MAC_EXPIRE_IFS);
                else
                    selfTimer(SIFS, MAC_EXPIRE_IFS);
            } else {
                deferPacket();
            }
            break;
        } /* unicast but no ACK received */

        case RDC_SEND_FATAL: /* fatal error, abort message */
        {
            // end MAC phase
            endMACphase();
            if (DEBUG)
                std::cout << "FATAL ERROR" << endl;
            selfTimer(0, MAC_EXPIRE_IFS);

            break;
        } /* fatal error, abort message */

        case RDC_SEND_COL: /* busy radio */
        {
            // radio/channel is busy, defer packet
            deferPacket();

            break;
        } /* busy radio */

        default:
            delete packet;
            if (DEBUG)
                std::cout << "Missing note" << endl;
            break;
        }

        delete packet; // done result
        break;
    } /* Result */

    default:
        delete packet;
        if (DEBUG)
            std::cout << "Unknown kind" << endl;
        break;
    }
}

}
/* namespace wsn_energy */
