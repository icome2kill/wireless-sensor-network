/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: net-layer energy, however, does not using this scheme anymore
 */

#ifndef __WSN_ENERGY_COUNT_H_
#define __WSN_ENERGY_COUNT_H_

#include <omnetpp.h>

#ifndef POWER
#define POWER          100000.0 // micro Jun 20 mJ#define E_ELEC         0.005 // micro 50  nJ#define E_FS         0.00001 // micro 10 pJ#define D                 50 // meters#endif

namespace wsn_energy {

class Count: public cSimpleModule {
protected:
    virtual void initialize();

public:
    double residualEnergy;

    void transmit(int numberOfBit);
    void receive(int numberOfBit);

};

} //namespace

#endif
