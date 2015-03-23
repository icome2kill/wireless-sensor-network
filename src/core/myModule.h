/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: interface for a layer
 */

#ifndef __WSN_ENERGY_TEST_H_
#define __WSN_ENERGY_TEST_H_

#include <omnetpp.h>
#include <strobe_m.h>

namespace wsn_energy {

class myModule : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();

    virtual void processSelfMessage(cPacket*) = 0;
    virtual void processUpperLayerMessage(cPacket*) = 0;
    virtual void processLowerLayerMessage(cPacket*) = 0;

    void sendMessageToUpper(cPacket*);
    void sendMessageToLower(cPacket*);

    void sendCommand(int);
    void sendResult(int);

  public:
    void selfTimer(double, int);
};

} //namespace

#endif
