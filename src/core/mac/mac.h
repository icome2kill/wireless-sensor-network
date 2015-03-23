/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: mac driver
 */

#ifndef MACDRIVER_H_
#define MACDRIVER_H_

#include "myModule.h"
#include <frame_m.h>

#ifndef IFS
#define IFS
#define MAX_SIFS_FRAME_SIZE 18 // octets
#define SIFS 0.000192          // 12 symbols
#define LIFS 0.00064           // 40 symbols
#endif

namespace wsn_energy {

class MACdriver: public myModule {
protected:
    Frame* bufferMAC;

    void initialize();
    void finish();

    /* main mechanism */
    void processSelfMessage(cPacket*) = 0;
    /* get command or original data from upper layer */
    void processUpperLayerMessage(cPacket*) = 0;
    /* process the results or package from lower layer */
    void processLowerLayerMessage(cPacket*) = 0;
    /* back-off transmitting, CCA is involved */
    virtual void deferPacket() = 0;

    /* encapsulate upper layer message */
    void encap(cPacket *packet);

    /* send buffer packet */
    void igniteRDCphase();

    /* tell RDC stop transmission phase */
    void endMACphase();

    /* accept input from lowerlayer */
    virtual void receiveFrame(Frame*);

public:
    // checking wrong/duplicated ACK in RDC
    int sequenceNumber;

    // 802.15.4 self address
    int linkLocalAddress;

    // 802.15.4 default router address
    int defaultRoute;
};

} /* namespace wsn_energy */

#endif /* RDCDRIVER_H_ */
