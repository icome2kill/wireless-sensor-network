/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: network layer, IPv6
 */

#ifndef NET_H_
#define NET_H_

#include <myModule.h>
#include <packet_m.h>
#include <segment_m.h>
#include <data_m.h>
#include "rpl.h"

#ifndef HOP_LIMIT
#define DEFAULT_HOP_LIMIT        64
#define HOP_LIMIT_COMPRESSED_1    1 // x01
#define HOP_LIMIT_COMPRESSED_64   2 // x10
#define HOP_LIMIT_COMPRESSED_128  3 // x11
#define HOP_LIMIT_NON_COMPRESSED  0 // carried in-line
#endif

namespace wsn_energy {

class IPv6 : public myModule
{
  private:
    IpPacketInterface* bufferNET;
    void preparePacketToBeSent();

  protected:
    void initialize();
    void finish();

    void processSelfMessage(cPacket*);
    void processUpperLayerMessage(cPacket*);
    void processLowerLayerMessage(cPacket*);

  public:
    int defaultRoute;

    std::list<IpPacketInterface*> ipPacketQueue; // Buffer message to send, public scope for debugging

    RPL *rpl; // using RPL as routing protocol

    void putIntoQueue(IpPacketInterface*); // put packet into queue

    void multicast(IcmpPacket*);        // multicast an icmp packet
    void unicast(UdpPacketInterface*);  // unicast an udp packet

    void resetDIOTimer();
};

}
;
// namespace

#endif /* NET_H_ */
