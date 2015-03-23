/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: radio duty cycling
 */

#ifndef RDCDRIVER_H_
#define RDCDRIVER_H_

//#ifndef WAIT_FOR_ACK_DURATION
//#define WAIT_FOR_ACK_DURATION 0.000864 // wait time of nullRDC
//#endif

// working phase
#define CHECKING_PHASE      0
#define TRANSMITTING_PHASE  1
#define FREE_PHASE          2

#include <myModule.h>
#include <frame_m.h>

namespace wsn_energy {

class Neighbor {
public:
    int senderID;
    int sequence;
    double phaseOptimization; // next time checking (because same check rate)
};

class RDCdriver: public myModule {
protected:
    // just send ACK <-- distinguish with data sending
    bool isSentACK;

    // MAC is waiting for nearly done CCA
    bool isHavingPendingTransmission;

    // MAC CCA or RDC CCA
    int ccaType;

    // CCA counter in 1 checking phase
    int ccaCounter;

    // CCA counter in 1 transmission turn
    int ccaInOneTurn;

    // For neighbor discovery protocol (NDP) - link-local aquire
    // For sequence checker
    // For phase optimization
    std::list<Neighbor*> neighbors;

    Command *ccaResult;
    Command *ccaTimeOut;
    Command *phaseTimeOut;

    Frame *bufferRDC;

    void initialize();
    void finish();

    bool cca();

    void processSelfMessage(cPacket*);
    void processUpperLayerMessage(cPacket*);
    void processLowerLayerMessage(cPacket*);

    /* demand radio layer*/
    void sendFrame();
    void on();
    void off();

    /* self process */
    virtual void selfProcess(cPacket*) = 0;

    /* command from MAC */
    virtual void beginTransmitting(int command) = 0;

    /* send packet */
    virtual void transmitFrame() = 0;

    /* receive success from PHY */
    virtual void receiveFrame(Frame*) = 0;

public:
    // working phase
    int phase;
};

} /* namespace wsn_energy */

#endif /* RDCDRIVER_H_ */
