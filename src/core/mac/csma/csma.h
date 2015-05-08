/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: unslotted csma
 */

#ifndef CSMA_H_
#define CSMA_H_

#include "mac.h"

namespace wsn_energy {

class csma : public MACdriver
{
  protected:
    virtual void deferPacket();
};

} /* namespace wsn_energy */

#endif /* CMSA_H_ */
