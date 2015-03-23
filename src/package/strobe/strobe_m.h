//
// Generated file, do not edit! Created by nedtool 4.6 from package/strobe/strobe.msg.
//

#ifndef _WSN_ENERGY_STROBE_M_H_
#define _WSN_ENERGY_STROBE_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace wsn_energy {

/**
 * Enum generated from <tt>package/strobe/strobe.msg:12</tt> by nedtool.
 * <pre>
 * // message kind
 * enum KIND
 * {
 * 
 *     DATA = 2; // BLUE   data to buffer lower/upper
 *     COMMAND = 4; // YELLOW command to lower
 *     RESULT = 1; // GREEN  result from lower
 * }
 * </pre>
 */
enum KIND {
    DATA = 2,
    COMMAND = 4,
    RESULT = 1
};

/**
 * Class generated from <tt>package/strobe/strobe.msg:19</tt> by nedtool.
 * <pre>
 * // Command 
 * packet Command
 * {
 *     int note;
 * }
 * </pre>
 */
class Command : public ::cPacket
{
  protected:
    int note_var;

  private:
    void copy(const Command& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Command&);

  public:
    Command(const char *name=NULL, int kind=0);
    Command(const Command& other);
    virtual ~Command();
    Command& operator=(const Command& other);
    virtual Command *dup() const {return new Command(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getNote() const;
    virtual void setNote(int note);
};

inline void doPacking(cCommBuffer *b, Command& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, Command& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>package/strobe/strobe.msg:24</tt> by nedtool.
 * <pre>
 * // Result 
 * packet Result
 * {
 *     int note;
 * }
 * </pre>
 */
class Result : public ::cPacket
{
  protected:
    int note_var;

  private:
    void copy(const Result& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Result&);

  public:
    Result(const char *name=NULL, int kind=0);
    Result(const Result& other);
    virtual ~Result();
    Result& operator=(const Result& other);
    virtual Result *dup() const {return new Result(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getNote() const;
    virtual void setNote(int note);
};

inline void doPacking(cCommBuffer *b, Result& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, Result& obj) {obj.parsimUnpack(b);}

/**
 * Enum generated from <tt>package/strobe/strobe.msg:29</tt> by nedtool.
 * <pre>
 * // Manual event
 * enum MANUAL_EVENT
 * {
 * 
 *     NODE_STARTUP = 0; // turn on a mote
 *     OUT_OF_ENERGY = 1; // out of energy flag
 *     NODE_DESTRUCT = 2; // turn off a mote (or) note runs out of energy
 * }
 * </pre>
 */
enum MANUAL_EVENT {
    NODE_STARTUP = 0,
    OUT_OF_ENERGY = 1,
    NODE_DESTRUCT = 2
};

/**
 * Enum generated from <tt>package/strobe/strobe.msg:36</tt> by nedtool.
 * <pre>
 * // App related
 * enum COMMAND_APP
 * {
 * 
 *     APP_ENVIRON_FLAG = 0; // data from enviroment, to sensor
 *     APP_SENSING_FLAG = 1; // data from sensor, to apps
 *     APP_READY_TO_SEND = 2; // data from apps, to trans
 * 
 *     RPL_SET_UP_DELAY = 3; // flag for delaying for setting up
 * 
 *     APP_SEND_LIGHT_DATA = 4;
 *     APP_SEND_HEAT_DATA_HIGH = 5;
 *     APP_SEND_HEAT_DATA_LOW = 6;
 *     APP_SEND_MOISTURE_DATA = 7;
 *     APP_SEND_SOIL_DATA_HIGH = 8;
 *     APP_SEND_SOIL_DATA_LOW = 9;
 * }
 * </pre>
 */
enum COMMAND_APP {
    APP_ENVIRON_FLAG = 0,
    APP_SENSING_FLAG = 1,
    APP_READY_TO_SEND = 2,
    RPL_SET_UP_DELAY = 3,
    APP_SEND_LIGHT_DATA = 4,
    APP_SEND_HEAT_DATA_HIGH = 5,
    APP_SEND_HEAT_DATA_LOW = 6,
    APP_SEND_MOISTURE_DATA = 7,
    APP_SEND_SOIL_DATA_HIGH = 8,
    APP_SEND_SOIL_DATA_LOW = 9
};

/**
 * Enum generated from <tt>package/strobe/strobe.msg:52</tt> by nedtool.
 * <pre>
 * // Net related
 * enum COMMAND_NET
 * {
 * 
 *     NET_TIMER_DIO = 0; // handle self-command handle DIO timer
 *     NET_TIMER_DIS = 1; // handle self-command handle DIS timer
 * 
 *     NET_CHECK_BUFFER = 2; // check packet buffer
 * }
 * </pre>
 */
enum COMMAND_NET {
    NET_TIMER_DIO = 0,
    NET_TIMER_DIS = 1,
    NET_CHECK_BUFFER = 2
};

/**
 * Enum generated from <tt>package/strobe/strobe.msg:60</tt> by nedtool.
 * <pre>
 * // MAC related
 * enum COMMAND_MAC
 * {
 * 
 *     MAC_CCA_REQUEST = 0; // request CCA, to PHY
 * 
 *     MAC_ASK_SEND_FRAME = 1; // ask RDC to send a transmission phase of a frame
 *     MAC_END_SEND_FRAME = 2; // tell RDC to stop a transmission phase
 * 
 *     MAC_IGNITE_RDC = 3; // start 1 duty in a transmission phase 
 * 
 *     MAC_EXPIRE_IFS = 5; // IFS has expired, ready for next frame
 * }
 * </pre>
 */
enum COMMAND_MAC {
    MAC_CCA_REQUEST = 0,
    MAC_ASK_SEND_FRAME = 1,
    MAC_END_SEND_FRAME = 2,
    MAC_IGNITE_RDC = 3,
    MAC_EXPIRE_IFS = 5
};

/**
 * Enum generated from <tt>package/strobe/strobe.msg:71</tt> by nedtool.
 * <pre>
 * enum RESULT_FROM_MAC
 * {
 * 
 *     MAC_FINISH_PHASE = 0; // finish 1 transmitting phase
 *     MAC_SEND_DEAD_NEIGHBOR = 1; // inform a dead neighbor
 *     MAC_RELIABLE = 2; // resend a failure message
 * }
 * </pre>
 */
enum RESULT_FROM_MAC {
    MAC_FINISH_PHASE = 0,
    MAC_SEND_DEAD_NEIGHBOR = 1,
    MAC_RELIABLE = 2
};

/**
 * Enum generated from <tt>package/strobe/strobe.msg:78</tt> by nedtool.
 * <pre>
 * // RDC related
 * enum COMMAND_RDC
 * {
 * 
 *     // command to radio
 *     RDC_TRANSMIT = 0; // transmit
 *     RDC_LISTEN = 1; // listen
 *     RDC_IDLE = 2; // idle
 * 
 *     // cca -> listening and then checking result, does not turn off radio	
 *     RDC_CCA_REQUEST = 3;
 * 
 *     // channel check
 *     RDC_PERIODICAL_MAJOR_CHECK = 4;
 *     RDC_PERIODICAL_MINOR_CHECK = 5;
 * 
 *     // self timer
 *     RDC_CCA_RESULT = 6; // cca result
 *     RDC_CCA_TIME_OUT = 7; // cca time out
 *     RDC_PHASE_TIME_OUT = 8; // phase time out
 * 
 *     // future message because of phase lock wait
 *     // begin a transmission turn (in one turn 6 maximum CCA + 1 trans)
 *     RDC_BEGIN_TRANS_TURN = 9;
 * }
 * </pre>
 */
enum COMMAND_RDC {
    RDC_TRANSMIT = 0,
    RDC_LISTEN = 1,
    RDC_IDLE = 2,
    RDC_CCA_REQUEST = 3,
    RDC_PERIODICAL_MAJOR_CHECK = 4,
    RDC_PERIODICAL_MINOR_CHECK = 5,
    RDC_CCA_RESULT = 6,
    RDC_CCA_TIME_OUT = 7,
    RDC_PHASE_TIME_OUT = 8,
    RDC_BEGIN_TRANS_TURN = 9
};

/**
 * Enum generated from <tt>package/strobe/strobe.msg:101</tt> by nedtool.
 * <pre>
 * enum RESULT_RDC
 * {
 * 
 *     // inform RDC is free	
 *     RDC_READY_TRANS_PHASE = 0; // begin transmission session, turn off periodical check
 * 
 *     // after 1 transmission turn (consists of one/many time(s))
 *     RDC_SEND_OK = 3; // send + receive ACK (if needed)
 *     RDC_SEND_NO_ACK = 4; // sent + no ACK (if needed)
 *     RDC_SEND_FATAL = 5; // fatal error, abort message
 *     RDC_SEND_COL = 6; // collision with PHY
 * 
 *     // CCA result
 *     CHANNEL_CLEAR = 7; // CCA clear
 *     CHANNEL_BUSY = 8; // CCA busy
 * }
 * </pre>
 */
enum RESULT_RDC {
    RDC_READY_TRANS_PHASE = 0,
    RDC_SEND_OK = 3,
    RDC_SEND_NO_ACK = 4,
    RDC_SEND_FATAL = 5,
    RDC_SEND_COL = 6,
    CHANNEL_CLEAR = 7,
    CHANNEL_BUSY = 8
};

/**
 * Enum generated from <tt>package/strobe/strobe.msg:117</tt> by nedtool.
 * <pre>
 * // PHY related
 * enum COMMAND_PHY
 * {
 * 
 *     PHY_SWITCH_TRANSMIT = 2; // switch to transmit mode
 *     PHY_BEGIN_TRANSMIT = 3; // begin transmitting
 *     PHY_END_TRANSMIT = 4; // ending transmitting
 * 
 *     PHY_SWITCH_LISTEN = 5; // switch to listening mode
 *     PHY_LISTENING = 6; // begin listening
 * 
 *     PHY_SWITCH_IDLE = 7; // switch to sleep mode 	
 *     PHY_IDLING = 8; // begin idling
 * }
 * </pre>
 */
enum COMMAND_PHY {
    PHY_SWITCH_TRANSMIT = 2,
    PHY_BEGIN_TRANSMIT = 3,
    PHY_END_TRANSMIT = 4,
    PHY_SWITCH_LISTEN = 5,
    PHY_LISTENING = 6,
    PHY_SWITCH_IDLE = 7,
    PHY_IDLING = 8
};

/**
 * Enum generated from <tt>package/strobe/strobe.msg:129</tt> by nedtool.
 * <pre>
 * enum RESULT_PHY
 * {
 * 
 *     // transmission result
 *     PHY_TX_OK = 12; // send okay
 *     PHY_TX_ERR = 13; // internal error, does not need to resend e.g: packet is too big
 * }
 * </pre>
 */
enum RESULT_PHY {
    PHY_TX_OK = 12,
    PHY_TX_ERR = 13
};

} // namespace wsn_energy

#endif // ifndef _WSN_ENERGY_STROBE_M_H_

