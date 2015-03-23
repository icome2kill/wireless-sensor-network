/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to nullMac.h
 */

#include "nullMAC.h"
#include "packet_m.h"

namespace wsn_energy {

Define_Module(nullMAC);

void nullMAC::deferPacket() {
    /* dismiss + announce failure duty */
    if (bufferMAC->getNumberTransmission() > 1) {
        delete bufferMAC;     // clear buffer
    }
    /* unslotted csma */
    else {
        /* request to perform CCA */
        Command *requestCCA = new Command;
        requestCCA->setKind(COMMAND);
        requestCCA->setNote(MAC_CCA_REQUEST);
        scheduleAt(simTime(), requestCCA);
    }
}

void nullMAC::processSelfMessage(cPacket* packet) {
    return;
}

void nullMAC::processUpperLayerMessage(cPacket* packet) {
    /* only process data packet */
    MACdriver::encap(packet);

    /* ignite RDC*/
    MACdriver::igniteRDCphase();
}

void nullMAC::processLowerLayerMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case DATA: /* Data */
    {
        // received message
        receiveFrame(check_and_cast<Frame*>(packet));
        break;
    } /* Data */

    default:
        delete packet;
        break;
    }
}

}
