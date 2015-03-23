/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: nullmac
 */

#ifndef NULLMAC_H_
#define NULLMAC_H_

#include "mac.h"

namespace wsn_energy {

class nullMAC: public MACdriver {
protected:
    virtual void deferPacket();
    void processSelfMessage(cPacket*);
    void processUpperLayerMessage(cPacket*);
    void processLowerLayerMessage(cPacket*);
};

} /* namespace wsn_energy */

#endif /* NULLMAC_H_ */
