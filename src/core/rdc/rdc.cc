/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to rdc.h
 */

#include <rdc.h>
#include "mac.h"
#include "radio.h"
#include "packet_m.h"
#include "signal_m.h"
#include "count.h"

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

void RDCdriver::initialize() {
    // initialization
    this->bufferRDC = NULL;
    this->isHavingPendingTransmission = false;
    this->isSentACK = false;
    this->ccaCounter = 0;

    // is on way of cca
    ccaResult = new Command;
    ccaResult->setKind(COMMAND);
    ccaResult->setNote(RDC_CCA_RESULT);

    // cca after detecting timer
    ccaTimeOut = new Command;
    ccaTimeOut->setKind(COMMAND);
    ccaTimeOut->setNote(RDC_CCA_TIME_OUT);

    // 1 transmitting phase timeout timer
    phaseTimeOut = new Command;
    phaseTimeOut->setKind(COMMAND);
    phaseTimeOut->setNote(RDC_PHASE_TIME_OUT);
}

void RDCdriver::finish() {
    if (this->bufferRDC != NULL) {
        delete bufferRDC;
        this->bufferRDC = NULL;
    }

    cancelAndDelete(ccaResult);
    cancelAndDelete(ccaTimeOut);
    cancelAndDelete(phaseTimeOut);
}

void RDCdriver::processSelfMessage(cPacket* packet) {
    selfProcess(packet);
}

void RDCdriver::processUpperLayerMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case DATA: /* Data */
    {
        // assign new frame
        this->bufferRDC = check_and_cast<Frame*>(packet);

        break;
    } /* Data */

    case COMMAND: /* Command */
    {
        this->beginTransmitting(check_and_cast<Command*>(packet)->getNote());
        delete packet; // done command
        break;
    } /* Command */

    default:
        ev << "Unknown kind" << endl;
        break;
    }
}

void RDCdriver::processLowerLayerMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case DATA: /* Data */
    {
        this->receiveFrame(check_and_cast<Frame*>(packet));
        break;
    } /* Data */

    default:
        delete packet;
        ev << "Unknown kind" << endl;
        break;
    }
}

void RDCdriver::sendFrame() {
    if (phase == TRANSMITTING_PHASE
            && phaseTimeOut->isScheduled() && bufferRDC != NULL) {
        bufferRDC->setAckRequired(true);
        sendMessageToLower(bufferRDC->dup());
        sendCommand(RDC_TRANSMIT);
    }
}

void RDCdriver::on() {
    sendCommand(RDC_LISTEN);
}

void RDCdriver::off() {
    // Server never sleep after listening/receiving and transmitting phase either
    if (getId() == simulation.getModuleByPath("server.rdc")->getId())
        return;

    sendCommand(RDC_IDLE);
}

bool RDCdriver::cca() {
    if ((check_and_cast<RadioDriver*>(getModuleByPath("^.radio")))->incomingSignal
            > 0)
        return true;
    else
        return false;
}

} /* namespace wsn_energy */
