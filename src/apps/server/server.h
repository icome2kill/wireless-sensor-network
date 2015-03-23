/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: Base-station app, construct network topology, receive data from mote
 */

#ifndef __WSN_ENERGY_SINK_H
#define __WSN_ENERGY_SINK_H

#include <myModule.h>
#include <macAddress.h>
#include <ipAddress.h>
#include <data_m.h>

#ifndef UDP_PORT
#define UDP_PORT
#define UDP_SERVER_PORT 5678 // UDP port
#define UDP_CLIENT_PORT 8765 // UDP port
#endif

namespace wsn_energy {

class Server : public myModule
{
  protected:
    virtual void initialize();

    virtual void processSelfMessage(cPacket*);
    virtual void processUpperLayerMessage(cPacket*);
    virtual void processLowerLayerMessage(cPacket*);

  public:
    MacAddress* macAddress;
    IpAddress* ipAddress;
};

}
;
// namespace

#endif
