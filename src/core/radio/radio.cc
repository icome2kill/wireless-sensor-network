#include "radio.h"

#include "world.h"
#include "statistic.h"
#include "energest.h"
#include "ipv6.h"
#include "math.h"

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

void RadioDriver::initialize() {
    this->bufferTXFIFO = NULL;
    this->isBufferOK = false;

    // Transmission power, programabble
    this->txPower = TXPOWER_MAX;

    // Range
    // d = d0*pow(10,(PL(d0) - PL(d))/(10*path_loss_exponent))
    //
    // indoor
    // d0 = 1m
    // PL(d0) = -37 dBm
    //
    // fluctuate     +- 10dBm
    // rssi accuracy +- 6dBm

    double d0 = 1.0;   // fixed
    double pl0 = -37.0; // fixed
    double pathLossExponent = 2.8;
    int signalFluctuate = 10;
//  int rssiAccuracy = 6;

    // expected Transmission range
    this->trRange = d0
            * pow(10,
                    (pl0 - (RX_SENSITIVITY + signalFluctuate))
                            / (10 * pathLossExponent));

    // expected Collision range
//  this->coRange = d0 * pow(10, (pl0 - (RSSI_SENSITIVITY + rssiAccuracy)) / (10 * pathLossExponent));
    this->coRange = this->trRange;

    if (DEBUG)
        std::cout << "Transmission range: " << this->trRange
                << " and Collision range: " << this->coRange << endl;

    this->par("trRange").setDoubleValue(trRange);
    this->par("coRange").setDoubleValue(coRange);

    // already turned on
    switchOscilatorMode(IDLE);
}

void RadioDriver::handleMessage(cMessage* msg) {
    if (this->status == POWER_DOWN) {
        delete msg;
        return;
    }

    myModule::handleMessage(msg);

    if (msg->arrivedOn("radioIn")) {
        if (DEBUG)
            ev << this->getFullName() << " received message from outside world"
                    << endl;
        this->received(check_and_cast<Raw*>(msg));
    }
}

void RadioDriver::finish() {
    if (this->bufferTXFIFO != NULL) {
        delete this->bufferTXFIFO;
        this->bufferTXFIFO = NULL;
    }
}

void RadioDriver::processSelfMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case COMMAND: /* Command */
    {
        int note = check_and_cast<Command*>(packet)->getNote();
        switch (note & 0x000000FF) {
        case PHY_SWITCH_TRANSMIT: /* switch to transmit */
        {
            if (!isBufferOK) {
                if (DEBUG)
                    ev << "Packet is too large" << endl;

                /* Feedback to RDC */
                sendResult(PHY_TX_ERR);

                // clear buffer
                if (this->bufferTXFIFO != NULL) {
                    delete this->bufferTXFIFO;
                    this->bufferTXFIFO = NULL;
                }

                switchOscilatorMode(IDLE);
            }
            /* Prepare transmitting */
            else {
                switch (this->status) {
                switchOscilatorMode(TRANSMITTING);

            case IDLE:
                selfTimer(SWITCH_MODE_DELAY_IDLE_TO_TRANS, PHY_BEGIN_TRANSMIT);
                break;

            case LISTENING:
                selfTimer(SWITCH_MODE_DELAY_LISTEN_TO_TRANS,
                        PHY_BEGIN_TRANSMIT);
                break;

            case TRANSMITTING:
                selfTimer(0, PHY_BEGIN_TRANSMIT);
                break;
                }
            }

            break;
        } /* switch to transmit */

        case PHY_SWITCH_LISTEN: /* switch to listen */
        {
            switchOscilatorMode(LISTENING);

            switch (this->status) {
            case IDLE:
                selfTimer(SWITCH_MODE_DELAY_IDLE_TO_LISTEN, PHY_LISTENING);
                break;

            case TRANSMITTING:
                selfTimer(SWITCH_MODE_DELAY_TRANS_TO_LISTEN, PHY_LISTENING);
                break;

            case LISTENING:
                selfTimer(0, PHY_LISTENING);
                break;
            }

            break;
        }/* switch to listen */

        case PHY_SWITCH_IDLE: /* switch to sleep */
        {
            switchOscilatorMode(IDLE);

            switch (this->status) {
            case IDLE:
                selfTimer(0, PHY_IDLING);
                break;

            case TRANSMITTING:
                selfTimer(SWITCH_MODE_DELAY_TRANS_TO_IDLE, PHY_IDLING);
                break;

            case LISTENING:
                selfTimer(SWITCH_MODE_DELAY_LISTEN_TO_IDLE, PHY_IDLING);
                break;
            }

            break;
        }/* switch to sleep */

        case PHY_BEGIN_TRANSMIT: /* begin transmitting*/
        {
            transmit_begin();

            break;
        }/* begin transmit */

        case PHY_END_TRANSMIT: /* end transmitting */
        {
            transmit_end();

            // Feedback to RDC
            sendResult(PHY_TX_OK);

            break;
        } /* end transmitting*/

        case PHY_LISTENING: /* begin listening*/
        {
            listen();

            break;
        }/* begin listening */

        case PHY_IDLING: /* idling */
        {
            sleep();

            break;
        }/* idling */

        case PHY_SWITCH_FREQ_CHANNEL: /* Switch to other channel */
        {
            this->freqChannel = (note & 0x0000FF00) >> 8;
            if (DEBUG) {
                std::cout << "[PHY] Freq: " << this->freqChannel << std::endl;
            }
            break;
        }
        default:
            ev << "Unknown command" << endl;
            break;
        }

        delete packet; // done command

        break;
    } /* Command */

    default:
        delete packet;
        ev << "Unknown kind" << endl;
        break;
    }
}

void RadioDriver::processUpperLayerMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case DATA: /* Data */
    {
        if (bufferTXFIFO != NULL) {
            delete bufferTXFIFO;
            bufferTXFIFO = NULL;
        }

        isBufferOK = Framer::createFramer(this->bufferTXFIFO,
                check_and_cast<Frame*>(packet));

        break;
    } /* Data */

    case COMMAND: /* Command */
    {
        int note = check_and_cast<Command*>(packet)->getNote();
        switch (note & 0x000000FF) {
        case RDC_CCA_REQUEST: /* CCA request */
        {
            selfTimer(0, PHY_SWITCH_LISTEN);

            break;
        } /* CCA request */

        case RDC_TRANSMIT: /* transmitting */
        {
            selfTimer(0, PHY_SWITCH_TRANSMIT);

            break;
        }/* transmitting */

        case RDC_LISTEN:/* turn on listening */
        {
            selfTimer(0, PHY_SWITCH_LISTEN);

            break;
        } /* turn on listening */

        case RDC_IDLE: /* turn off listening */
        {
            selfTimer(0, PHY_SWITCH_IDLE);

            break;
        }/* turn off listening */

        case RDC_SWITCH_FREQ_CHANNEL: {
            int commandCode = (note & 0x0000FF00)
                    | PHY_SWITCH_FREQ_CHANNEL;
            selfTimer(0, commandCode);
            break;
        }

        default:
            ev << "Unknown command" << endl;
            break;
        }
        delete packet; // done command
        break;
    } /* Command */

    default:
        delete packet;
        ev << "Unknown kind" << endl;
        break;
    }
}

void RadioDriver::processLowerLayerMessage(cPacket* packet) {
    /* It is the lowest layer */
}

/*
 * Begin transmitting
 */
void RadioDriver::transmit_begin() {
    if (DEBUG)
        ev << "PHY: begin transmitting" << endl;

    // register
    check_and_cast<World*>(simulation.getModuleByPath("world"))->registerHost(
            this, this->bufferTXFIFO);

    // switch mode
    switchOscilatorMode(TRANSMITTING);

    // calculate finish time
    double finishTime = bufferTXFIFO->getByteLength() * 8 / DATA_RATE;

    selfTimer(finishTime, PHY_END_TRANSMIT);
}

/*
 *  End transmitting
 */
void RadioDriver::transmit_end() {
    if (DEBUG)
        ev << "PHY: end transmitting" << endl;

    (check_and_cast<World*>(simulation.getModuleByPath("world")))->releaseHost(
            this);

    // switch mode
    switchOscilatorMode(IDLE);

    // clear buffer
//  if (this->bufferTXFIFO != NULL)
//  {
//    delete this->bufferTXFIFO;
//    this->bufferTXFIFO = NULL;
//  }
}

/*
 *   Turn on receiving
 */
void RadioDriver::listen() {
    if (DEBUG)
        ev << "PHY: LISTEN" << endl;

    (check_and_cast<World*>(simulation.getModuleByPath("world")))->beginListening(
            this);
}

/*
 *   Callback after receiving
 */
void RadioDriver::received(Raw* raw) {
    // consider bit error
    if (!raw->hasBitError()) {
        if (DEBUG)
            ev << "PHY: RECEIVED" << endl;

        sendMessageToUpper(raw->decapsulate());
    }

    delete raw;
}

/*
 *   Idle
 */
void RadioDriver::sleep() {
    if (DEBUG)
        ev << "IDLE (PHY)" << endl;

    ((World*) simulation.getModuleByPath("world"))->stopListening(this);
}

/*
 * Switch oscilator mode
 */
void RadioDriver::switchOscilatorMode(int type) {
    switch (type) {
    case IDLE:
        this->status = IDLE;
        if (simulation.getModuleByPath("WSN") != NULL) {
            (check_and_cast<Energest*>(
                    getParentModule()->getSubmodule("energest")))->energestOff(
                    ENERGEST_TYPE_TRANSMIT);
            (check_and_cast<Energest*>(
                    getParentModule()->getSubmodule("energest")))->energestOff(
                    ENERGEST_TYPE_LISTEN);
            (check_and_cast<Energest*>(
                    getParentModule()->getSubmodule("energest")))->energestOn(
                    ENERGEST_TYPE_IDLE, getIdPower());
        }
        (&getParentModule()->getDisplayString())->setTagArg("i", 1, IDLE_COLOR);
        break;

    case LISTENING:
        this->status = LISTENING;
        if (simulation.getModuleByPath("WSN") != NULL) {
            (check_and_cast<Energest*>(
                    getParentModule()->getSubmodule("energest")))->energestOff(
                    ENERGEST_TYPE_IDLE);
            (check_and_cast<Energest*>(
                    getParentModule()->getSubmodule("energest")))->energestOff(
                    ENERGEST_TYPE_TRANSMIT);
            (check_and_cast<Energest*>(
                    getParentModule()->getSubmodule("energest")))->energestOn(
                    ENERGEST_TYPE_LISTEN, getRxPower());
        }
        (&getParentModule()->getDisplayString())->setTagArg("i", 1,
        LISTEN_COLOR);
        break;

//    case RECEIVING:
//      this->status = RECEIVING;
//      (check_and_cast<Energest*>(getParentModule()->getSubmodule("energest")))->energestOff(ENERGEST_TYPE_IDLE);
//      (check_and_cast<Energest*>(getParentModule()->getSubmodule("energest")))->energestOff(ENERGEST_TYPE_TRANSMIT);
//      (check_and_cast<Energest*>(getParentModule()->getSubmodule("energest")))->energestOn(ENERGEST_TYPE_LISTEN,
//          getRxPower());
//      (&getParentModule()->getDisplayString())->setTagArg("i", 1, RECEIVING_COLOR);
//      break;

    case TRANSMITTING:
        this->status = TRANSMITTING;
        if (simulation.getModuleByPath("WSN") != NULL) {

            (check_and_cast<Energest*>(
                    getParentModule()->getSubmodule("energest")))->energestOff(
                    ENERGEST_TYPE_IDLE);
            (check_and_cast<Energest*>(
                    getParentModule()->getSubmodule("energest")))->energestOff(
                    ENERGEST_TYPE_LISTEN);
            (check_and_cast<Energest*>(
                    getParentModule()->getSubmodule("energest")))->energestOn(
                    ENERGEST_TYPE_TRANSMIT, getTxPower());
        }
        (&getParentModule()->getDisplayString())->setTagArg("i", 1,
        TRANSMIT_COLOR);
        break;

    case POWER_DOWN: // Turn off
    {
        this->status = POWER_DOWN;
        (&getParentModule()->getDisplayString())->setTagArg("i", 1, OFF_COLOR);

        // remove preferred parent connection
        IPv6* net = check_and_cast<IPv6*>(
                getParentModule()->getSubmodule("net"));
        if (net->rpl->rplDag->preferredParent != NULL) {
            char channelParent[20];
            sprintf(channelParent, "out %d to %d",
                    this->getParentModule()->getId(),
                    simulation.getModule(
                            net->rpl->rplDag->preferredParent->neighborID)->getParentModule()->getId());
            getParentModule()->gate(channelParent)->setDisplayString("ls=,0");
        }

        break;
    }
    }
}
}  // namespace wsn_energy
