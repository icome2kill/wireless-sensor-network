/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: Transport layer functions
 */


#ifndef __WSN_ENERGY_TRANSPORT_H_
#define __WSN_ENERGY_TRANSPORT_H_

#include <myModule.h>
#include <segment_m.h>
#include <data_m.h>

#ifndef UDP_PORT
#define UDP_PORT
#define UDP_SERVER_PORT 5678 // UDP port
#define UDP_CLIENT_PORT 8765 // UDP port
#endif

namespace wsn_energy {

class UDP : public myModule
{
  protected:
    virtual void processSelfMessage(cPacket*);
    virtual void processUpperLayerMessage(cPacket*);
    virtual void processLowerLayerMessage(cPacket*);
};

} //namespace

#endif
