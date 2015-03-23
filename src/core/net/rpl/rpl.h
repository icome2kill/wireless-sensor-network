/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: RPL logic, trickler timer, DIO processing, next-hop decision
 */

#ifndef RPL_H_
#define RPL_H_

#include <list>
#include <packet_m.h>
#include <strobe_m.h>

#define RANK_INFINITY 0xffff

namespace wsn_energy {

/* forward declaration */
class IPv6;

class NodeQuality
{
  public:
    int hopCount; // hop count from base station to this neighbor
};

class LinkQuality
{
  public:
    double etx; // expected transmission number
};

class RPL_neighbor
{
  public:
    int neighborID; // IPv6 of neighbor
    unsigned long neighborRank; // rank of this neighbor

    NodeQuality nodeQuality; // quality of this neighbor
    LinkQuality linkQuality; // quality of link between this neighbor and ownner mote
};

class RPL_dag
{
  public:
    /* DODAG information*/
    bool joined; // is this node involved in the DODAG
    int dodagID; // ID of DODAG (IP of base station)
    int version; // version of DODAG
    int minHopRankInc; // Min hop rank increment

    unsigned long rank; // Owner rank

    /* routing information */
    RPL_neighbor *preferredParent; // default-upward route
    std::list<RPL_neighbor*> parentList; // list of neighbor with better rank
    std::list<RPL_neighbor*> siblingList; // list of neighbor with same rank

    // Objective Function
    RPL_neighbor* bestParent(RPL_neighbor*, RPL_neighbor*);
    int calculateRank(RPL_neighbor*);
    RPL_neighbor* updatePreferredParent(std::list<RPL_neighbor*>);
};

class RPL
{
  private:
    IPv6 *net; // Net-layer owner

    int dioCounter;
    int dioCurrent;
    unsigned long dioInterval;
    double dioDelay;
    bool isDIOsent;
    bool isDISsent;

    Command *dioTimer;
    Command *disTimer;

    void newDIOinterval();

    void processDIO(DIO*);
    void processDIS(DIS*);

  public:
    RPL_dag *rplDag;

    RPL(IPv6 *net);

    void rpl_init();
    void rpl_set_root();
    void finish();

    void sendDIO();
    void sendDIS();

    void hasSentDIO();
    void hasSentDIS();

    void processICMP(IcmpPacket*);

    void resetDIOTimer();
    void resetDISTimer();

    void handleDIOTimer();
    void handleDISTimer();

    void updatePrefferredParent();
    void purgeRoute();
};

} /* namespace wsn_energy */

#endif /* RPL_H_ */
