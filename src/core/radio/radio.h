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

#ifndef RADIO_H_
#define RADIO_H_

#include "myModule.h"
#include "signal_m.h"
#include "framer.h"

/*
 * Specification for CC2420
 */
#ifndef CC2420
#define CC2420
#define CHANNEL                26   // channel name
#define FREQUENCY          2400.0   // MHz
#define DATA_RATE        250000.0   // bit per second
#define TXPOWER_MAX           0.0   // dBm
#define TXPOWER_MIN         -24.0   // dBm
#define RX_SENSITIVITY      -94.0   // dBm
#define RSSI_SENSITIVITY   -100.0   // dBm
#define CCA_THRESHOLD       -77.0   // dBm, default, programable RSSI.CCA_THR
#define CCA_PERIOD          00128   // seconds
//#define TXPOWER_CURRENT_MAX  17.4   // mA
//#define RXPOWER_CURRENT      18.8   // mA
//#define IDPOWER_CURRENT       0.426 // mA
#define TXPOWER_CURRENT_MAX  21.8   // mA (MCU on)
#define RXPOWER_CURRENT      19.5   // mA (MCU on)
#define IDPOWER_CURRENT       1.8   // mA (MCU on)
#define SUPPLY_VOLTAGE        3.3   // V, VREG_IN
// working delay
#define SYMBOL                             0.000016   // 1 symbol = 4/250 millisecond
#define SWITCH_MODE_DELAY_IDLE_TO_TRANS    0.000192   // 12 symbols
#define SWITCH_MODE_DELAY_IDLE_TO_LISTEN   0.000192   // 12 symbols
#define SWITCH_MODE_DELAY_TRANS_TO_LISTEN  0.000384   // 24 symbols
#define SWITCH_MODE_DELAY_TRANS_TO_IDLE    0          // 0 symbol
#define SWITCH_MODE_DELAY_LISTEN_TO_TRANS  0.000384   // 24 symbols
#define SWITCH_MODE_DELAY_LISTEN_TO_IDLE   0          // 0 symbol
#endif

#ifndef WORKING_MODE
#define WORKING_MODE
#define POWER_DOWN      0 // power down
#define IDLE            1 // do nothing (free)
#define TRANSMITTING    2 // transmitting (busy)
#define LISTENING       3 // listening to nothing (free)
//#define RECEIVING       4 // listening to something (busy)
#define OFF_COLOR       "black"
#define IDLE_COLOR      "brown"
#define TRANSMIT_COLOR  "blue"
#define LISTEN_COLOR    "yellow"
//#define RECEIVING_COLOR "orange"
#endif

namespace wsn_energy {

class RadioDriver : public myModule
{
  private:
    bool isBufferOK;
    Raw* bufferTXFIFO; // buffered transmit mode(TX_MODE 0) 128 bytes TXFIFO, in CC2420 RAM

    // Self functioning
    void transmit_begin();
    void transmit_end();
    void listen();
    void received(Raw*);
    void sleep();

    // CCA return CCA interval
    virtual double intervalCCA() = 0;

    // power
    virtual double getTxPower() = 0;
    virtual double getRxPower() = 0;
    virtual double getIdPower() = 0;

  protected:
    void initialize();
    void handleMessage(cMessage*);
    void finish();

    // processing
    void processSelfMessage(cPacket*);
    void processUpperLayerMessage(cPacket*);
    void processLowerLayerMessage(cPacket*);

  public:
    int incomingSignal;        // number of sensing signal (tranmitting + sensing)
    bool ccaIsFreeChannel; // cca result
    int status;     // sleep, transmitting, listening, receiving
    double txPower; // transmit power
    double trRange; // simulated transmission range according to txPower
    double coRange; // simulated collission range according to txPower

    void switchOscilatorMode(int mode);    // Switch oscilator mode, public for being manipulated by energest, bytecount
};

} /* namespace wsn_energy */

#endif /* RADIO_H_ */
