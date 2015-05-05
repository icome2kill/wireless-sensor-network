//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef CONTIKIMAC_H_
#define CONTIKIMAC_H_

#include "rdc.h"
#include "packet_m.h"

#ifndef RDC
#define RDC
// value of ACK length header
#define ACK_LENGTH          5
// CCA type in checking phase
#define RDC_CHECK_CCA       0
#define RDC_TRANS_CCA       1
#define MAC_CCA             2
// check rate
#define CHANNEL_CHECK_RATE      8        // Hertz#define CHANNEL_CHECK_INTERVAL   0.03125    // second// CCA configuration
#define CCA_TRANS_MAX            6        // maximum number of CCA before transmitting#define CCA_COUNT_MAX            2        // maximum number of CCA per check#define CCA_CHECK_TIME           0.000122 // time to perform a CCA (20 symbols)#define CCA_SLEEP_TIME           0.0005   // interval between each CCA// reaction
#define LISTEN_AFTER_DETECT      0.0125   // second, interval after detecting a strobe#define INTER_FRAME_INTERVAL     0.004    // second, interval between each frame in a transmission phases#define MAX_PHASE_STROBE         0.145488 // second, time for a transmission phases (1 check interval + 2 check phases)// packet size
#define SHORTEST_PACKET_SIZE     23       // octets#endif

namespace wsn_energy {

class contikiMAC: public RDCdriver {
protected:
    void initialize();
    void processLowerLayerMessage(cPacket*);

    /* MAC call-back */
    void enterMACtransmissonPhase();
    void quitMACtransmissonPhase();

    /* RDC transmission turn */
    void enterRDCtransmissionPhase();
    void quitRDCtransmissionPhase(int result);

    virtual void selfProcess(cPacket*);

    /* command from MAC */
    virtual void beginTransmitting(int);

    /* send packet */
    virtual void transmitFrame();

    /* receive success from PHY */
    virtual void receiveFrame(Frame*);
};

} /* namespace wsn_energy */

#endif /* RDC_H_ */
