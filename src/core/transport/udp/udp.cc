/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to udp.h
 */


#include "udp.h"
#include "statistic.h"

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

Define_Module(UDP);

void UDP::processSelfMessage(cPacket* packet)
{
}

void UDP::processUpperLayerMessage(cPacket* packet)
{
  switch (packet->getKind())
  {
    case DATA: /* Data */
    {
      /* statistics */
      (check_and_cast<Statistic*>(getModuleByPath("^.^.statistic"))->registerStatistic(IP_TRANS));

      // create interface
      UdpPacketInterface *udpPacket;

      if (getModuleByPath("^.^")->par("usingHDC").boolValue())
      {
        // compress using HC01

        // initialisation
        udpPacket = new UdpPacketCompressed;
        udpPacket->setKind(DATA);
        udpPacket->setByteLength(udpPacket->getHeaderLength());

        // set up compressed type and value after compressed

        // set up port
        (check_and_cast<UdpPacketCompressed*>(udpPacket))->setInlineUdpSourcePort(UDP_CLIENT_PORT);
        (check_and_cast<UdpPacketCompressed*>(udpPacket))->setInlineUdpDestinationPort(
            (check_and_cast<Data*>(packet))->getDestinationPort());

        // length (in-line pseudo-header)
        // checksum (in-line pseudo-header)
      }
      else
      {
        // initialisation
        udpPacket = new UdpPacketStandard;
        udpPacket->setKind(DATA);
        udpPacket->setByteLength(udpPacket->getHeaderLength());

        // set up port
        (check_and_cast<UdpPacketStandard*>(udpPacket))->setSourcePort(UDP_CLIENT_PORT);
        (check_and_cast<UdpPacketStandard*>(udpPacket))->setDestinationPort(
            (check_and_cast<Data*>(packet))->getDestinationPort());

        // length (in-line pseudo-header)
        // checksum (in-line pseudo-header)
      }

      // encapsulate data
      udpPacket->encapsulate(packet);

      sendMessageToLower(udpPacket);

      break;
    } /* Data */

    default:
      delete packet;
      ev << "Unknown kind" << endl;
      break;
  }
}

void UDP::processLowerLayerMessage(cPacket* packet)
{
  int packetDestinationPort;

  if (getModuleByPath("^.^")->par("usingHDC").boolValue())
  {
    // compress using HC01
    packetDestinationPort = (check_and_cast<UdpPacketCompressed*>(packet))->getInlineUdpDestinationPort();
  }
  else
  {
    // normal header
    packetDestinationPort = (check_and_cast<UdpPacketStandard*>(packet))->getDestinationPort();
  }

  // Has reached approciate port
  if (packetDestinationPort == UDP_SERVER_PORT)
  {
    if (DEBUG)
      ev << "Arrived base station !!!" << endl;

    // get data and send to receiver application
    sendMessageToUpper(packet->decapsulate());
  }
  else
  {
    // Message arrived at port not listening
    // Drop it
  }

  delete packet;
}

} //namespace
