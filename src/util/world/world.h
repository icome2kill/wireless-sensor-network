/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: Managing position, signal
 */

#ifndef ENVIROMENT_H_
#define ENVIROMENT_H_

#include <omnetpp.h>
#include "mySignal.h"
#include "radio.h"

#ifndef CONNECTION_STATUS
#define CONNECTION_STATUS
#define NO_CONNECTION 0 // out of range
#define WITHIN_TRANS  1 // within transmission range
#define WITHIN_COLLI  2 // within collision range
#endif

namespace wsn_energy {

// mote distance information, neccessary to calculate transmit/collision range
class NeighborInformation
{
    int moteID;               // the ID of destination mote
    double distance;          // distance from self to the destination mode
};

// mote information, to manage signals
class Mote
{
  public:
    int moteID; // id of mote
    std::list<NeighborInformation> moteNeighborDistance; // neighbor information

    Raw* onAir; // on air packet
    std::list<int> moteIDWithinTransmissionRange; // mote in transmission range, create signal
    std::list<int> moteIDWithinCollisionRange;    // mote out of transmission range, increase incoming signal
};

class World : public cSimpleModule
{
  private:
    int numberClient;           // total number of client
    std::ostringstream oss;     // string buffer

    void arrangeMotes(); // Arrange nodes in positions
    void connectNodes(); // Connect adjacent nodes

    void deployConnection(RadioDriver*);                // deploy all valid connection for a given radio
    int validateConnection(RadioDriver*, RadioDriver*); // check validation between 2 radio

    void considerSignal(mySignal*);     // register on-air signal

  protected:
    void initialize();
    void finish();

  public:
    std::list<Mote*> hosts;   // array of host list (Host)
    std::list<mySignal*> signals; // array of all on-air signal (mySignal)

    void registerHost(RadioDriver*, Raw*);    // register transmitting mote
    void releaseHost(RadioDriver*);           // unregister transmitting mote

    void beginListening(RadioDriver*);  // recver begin listening
    void stopListening(RadioDriver*);   // recver stop listening

    double calculateDistance(RadioDriver*, RadioDriver*);  // calculate distance between 2 motes
    double calculateDistance(int, int, int, int);        // calculate distance according to 2D coordinate
};

} /* namespace wsn_energy */

#endif /* ENVIROMENT_H_ */
