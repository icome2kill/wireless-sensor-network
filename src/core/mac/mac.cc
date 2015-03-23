/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to mac.h
 */

#include <mac.h>
#include "packet_m.h"
#include "statistic.h"
#include "ipv6.h"

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

void MACdriver::initialize() {
    this->bufferMAC = NULL;
    this->sequenceNumber = 0;
    this->linkLocalAddress = 0;
    this->defaultRoute = 0;
}

void MACdriver::finish() {
    if (this->bufferMAC != NULL) {
        delete this->bufferMAC;
        this->bufferMAC = NULL;
    }
}

void MACdriver::encap(cPacket* packet) {
    /* only process data packet */

    if (getModuleByPath("^.^")->par("usingHDC").boolValue()) {
        // compress using HC01

        // intialisation
        bufferMAC = new FrameDataCompressed;
        bufferMAC->setKind(DATA);
        bufferMAC->setByteLength(bufferMAC->getHeaderLength());

        /*  meta data */
        bufferMAC->setNumberTransmission(0);

        // FCF
        bufferMAC->setFrameType(FRAME_DATA);
        bufferMAC->setPanIdCompression(true);

        // increase sequence number
        this->sequenceNumber++;

        // sequence number
        (check_and_cast<FrameDataCompressed*>(bufferMAC))->setDataSequenceNumber(
                this->sequenceNumber);

        // address fields

        // originator - final destination
        (check_and_cast<FrameDataCompressed*>(bufferMAC))->setOrginatorMacAddress(
                simulation.getModule(
                        check_and_cast<IpPacketCompressed*>(packet)->getMetaSourceIpAddress())->getModuleByPath(
                        "^.mac")->getId());

        if (check_and_cast<IpPacketCompressed*>(packet)->getMetaDestinationIpAddress()
                != 0)
            (check_and_cast<FrameDataCompressed*>(bufferMAC))->setFinalDestinationMacAddress(
                    simulation.getModule(
                            check_and_cast<IpPacketCompressed*>(packet)->getMetaDestinationIpAddress())->getModuleByPath(
                            "^.mac")->getId());
        else
            (check_and_cast<FrameDataCompressed*>(bufferMAC))->setFinalDestinationMacAddress(
                    0);

        // hop count
        (check_and_cast<FrameDataCompressed*>(bufferMAC))->setHopLeft(
                check_and_cast<IpPacketCompressed*>(packet)->getMetaHopLimit());

        // next hop
        if (check_and_cast<IpPacketCompressed*>(packet)->getMetaDestinationIpAddress()
                == 0) {
            (check_and_cast<FrameDataCompressed*>(bufferMAC))->setSourceMacAddress(
                    this->getId());
            (check_and_cast<FrameDataCompressed*>(bufferMAC))->setDestinationMacAddress(
                    0);

            bufferMAC->setAckRequired(false);
        } else {
            // using default route
            if (defaultRoute == 0) {
                // fatal error, abort message
                if (DEBUG)
                    std::cout << "FATAL NET ERROR" << endl;

                sendResult(MAC_RELIABLE);
                selfTimer(0, MAC_EXPIRE_IFS);

                return;
            } else {
                // using NDP
                (check_and_cast<FrameDataCompressed*>(bufferMAC))->setSourceMacAddress(
                        this->getId());
                (check_and_cast<FrameDataCompressed*>(bufferMAC))->setDestinationMacAddress(
                        defaultRoute);
            }

            bufferMAC->setAckRequired(true);
        }
    } else {
        // intialisation
        bufferMAC = new FrameDataStandard;
        bufferMAC->setKind(DATA);
        bufferMAC->setByteLength(bufferMAC->getHeaderLength());

        /*  meta data */
        bufferMAC->setNumberTransmission(0);

        // FCF
        bufferMAC->setFrameType(FRAME_DATA);
        bufferMAC->setPanIdCompression(false);

        // increase sequence number
        this->sequenceNumber++;

        // sequence number
        (check_and_cast<FrameDataStandard*>(bufferMAC))->setDataSequenceNumber(
                this->sequenceNumber);

        // address fields
        if (check_and_cast<IpPacketStandard*>(packet)->getDestinationIpAddress()
                == 0) {
            (check_and_cast<FrameDataStandard*>(bufferMAC))->setSourceMacAddress(
                    this->getId());
            (check_and_cast<FrameDataStandard*>(bufferMAC))->setDestinationMacAddress(
                    0);

            bufferMAC->setAckRequired(false);
        } else {
            // using default route
            int netDefaultRoute = (check_and_cast<IPv6*>(
                    getModuleByPath("^.net")))->defaultRoute;

            if (netDefaultRoute == 0) {
                // fatal error, abort message
                if (DEBUG)
                    std::cout << "FATAL NET ERROR" << endl;

                sendResult(MAC_RELIABLE);
                selfTimer(0, MAC_EXPIRE_IFS);

                return;
            } else {
                // using ARP
                defaultRoute =
                        simulation.getModule(netDefaultRoute)->getModuleByPath(
                                "^.mac")->getId();

                (check_and_cast<FrameDataStandard*>(bufferMAC))->setSourceMacAddress(
                        this->getId());
                (check_and_cast<FrameDataStandard*>(bufferMAC))->setDestinationMacAddress(
                        defaultRoute);
            }

            bufferMAC->setAckRequired(true);
        }
    }

    bufferMAC->encapsulate(packet);

    /* statistics */
    if (bufferMAC->getAckRequired())
        (check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
        MAC_SEND));
}

void MACdriver::igniteRDCphase() {
    if (DEBUG)
        ev << "MAC: ignite RDC" << endl;

    /* begin a transmission turn */
    sendCommand(MAC_IGNITE_RDC);
}

void MACdriver::endMACphase() {
    if (DEBUG)
        ev << "MAC: end transmission phase" << endl;

    /* told RDC end a transmission phase */
    sendCommand(MAC_END_SEND_FRAME);
}

void MACdriver::receiveFrame(Frame* frameMac) {
    if (DEBUG)
        ev << "MAC: received" << endl;

    if (getModuleByPath("^.^")->par("usingHDC").boolValue()) {
        // compress using HC01

        // check right hop
        if (check_and_cast<FrameDataCompressed*>(frameMac)->getDestinationMacAddress()
                == 0
                || (check_and_cast<FrameDataCompressed*>(frameMac)->getDestinationMacAddress()
                        == getId()
                        && check_and_cast<FrameDataCompressed*>(frameMac)->getSourceMacAddress()
                                != defaultRoute)) {
            // right MAC destination
            sendMessageToUpper(frameMac);

            /* statistics */
            if (check_and_cast<FrameDataCompressed*>(frameMac)->getDestinationMacAddress()
                    == getId())
                (check_and_cast<Statistic*>(
                simulation.getModuleByPath("statistic"))->registerStatistic(
                MAC_RECV));
        } else {
            delete frameMac;
        }
    } else {
        if (check_and_cast<FrameDataStandard*>(frameMac)->getDestinationMacAddress()
                == 0
                || (check_and_cast<FrameDataStandard*>(frameMac)->getDestinationMacAddress()
                        == getId()
                        && check_and_cast<FrameDataStandard*>(frameMac)->getSourceMacAddress()
                                != defaultRoute)) {
            // right MAC destination
            sendMessageToUpper(frameMac->decapsulate());

            /* statistics */
            if (check_and_cast<FrameDataStandard*>(frameMac)->getDestinationMacAddress()
                    == getId())
                (check_and_cast<Statistic*>(
                simulation.getModuleByPath("statistic"))->registerStatistic(
                MAC_RECV));

            delete frameMac;
        } else {
            delete frameMac;
        }
    }
}

} /* namespace wsn_energy */
