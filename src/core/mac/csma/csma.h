/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: unslotted csma
 *                  checking availability of channel before sending
 *                  deferring packet to avoid collision
 */

#ifndef CSMA_H_
#define CSMA_H_

#include "mac.h"

namespace wsn_energy {

class csma: public MACdriver {
protected:
    void deferPacket();
    void processSelfMessage(cPacket*);
    void processUpperLayerMessage(cPacket*);
    void processLowerLayerMessage(cPacket*);
};

} /* namespace wsn_energy */

#endif /* CMSA_H_ */
