/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: statistics and exporting functions
 */

#ifndef __TRACKINGWSN_STATCOLLECTOR_H_
#define __TRACKINGWSN_STATCOLLECTOR_H_

#include <omnetpp.h>

#ifndef DEFINE
#define DEFINE
#define APP_SEND 0
#define APP_RECV 1
#define NET_SEND 2
#define NET_RECV 3
#define MAC_SEND 4
#define MAC_RECV 5
#define RADIO_SEND 6
#define RADIO_RECV 7
#define DIO_SENT   8
#define DIS_SENT   9
#define IP_INTER   10
#define IP_TRANS   11
#define LIFE_TIME_INCREASE_SERVER_NEIGHBOR  12
#define LIFE_TIME_DECREASE_SERVER_NEIGHBOR  13
#define LIFE_TIME_PERCENTAGE_DEAD_NODE      14
#define LIFE_TIME_FIRST_DEAD_NODE           15
#define DELAY_APP_LAYER 16
#define DELAY_NET_LAYER 17
#define APP_SEND_HEAT 18
#define APP_RECV_HEAT 19
#define APP_RECV_HEAT_DELAY 20
#define APP_SEND_LIGHT 21
#define APP_RECV_LIGHT 22
#define APP_RECV_LIGHT_DELAY 23
#define APP_SEND_MOISTURE 24
#define APP_RECV_MOISTURE 25
#define APP_RECV_MOISTURE_DELAY 26
#define APP_SEND_SOIL 27
#define APP_RECV_SOIL 28
#define APP_RECV_SOIL_DELAY 29

#endif

namespace wsn_energy {

/**
 * Statistics Collector
 */
class Statistic : public cSimpleModule
{
  private:
    /* energy */
    cMessage *polling; // Timer for polling total sensor energy
    cMessage *pollingCount; // Timer for polling total sensor energy (Hung's method)

    double numNetworkEnergyCount; // Energy of all network (Hung's method)
    simsignal_t sigNetworkEnergyCount;

    double numSensorEnergyCount; // Energy for each distributed node (Hung's method)
    simsignal_t sigSensorEnergyCount;

    double numNetworkEnergy; // Energy of all network
    simsignal_t sigNetworkEnergy;

    double numSensorEnergy; // Energy for each distributed node
    simsignal_t sigSensorEnergy;

    double numSensorEnergyLevel; // Energy for each distributed node
    simsignal_t sigSensorEnergyLevel;

    double numTotalEnergy;  // Energy remaining in whole network
    simsignal_t sigTotalEnergy;

    /* total delay */
    double numTotalDelayApp; // Total delay app layer
    simsignal_t sigTotalDelayApp;

    double numTotalDelayNet;  // Total delay net layer
    simsignal_t sigTotalDelayNet;

    /* packet number*/
    int numRadioSend; // Number of radio message to send
    int numRadioRecv; // Number of radio failed due to collision, nor incomplete
    simsignal_t sigRadioSend;
    simsignal_t sigRadioRecv;

    int numMacSend; // Number of frame to send
    int numMacRecv; // Number of failed frame sending
    simsignal_t sigMacSend;
    simsignal_t sigMacRecv;

    int numNetSend; // Number of IpPacket to send
    int numNetRecv; // Number of failed IpPacket sending
    simsignal_t sigNetSend;
    simsignal_t sigNetRecv;

    int numAppSend; // Number of data sending by client
    int numAppRecv; // Number of recv recving by server
    simsignal_t sigAppSend;
    simsignal_t sigAppRecv;

    /* duty cycling tracking */
    double timeTrans;
    double timeListen;
    double timeIdle;

    simsignal_t sigTimeTrans;
    simsignal_t sigTimeListen;
    simsignal_t sigTimeIdle;

    /* number of each packet type in net layer */
    int numDIOsent;
    int numDISsent;
    int numIPinter;
    int numIPtrans;

    simsignal_t sigNumDIOsent;
    simsignal_t sigNumDISsent;
    simsignal_t sigNumIPinter;
    simsignal_t signumIPtrans;

    /* network life time*/
    int numServerNeighbor;
    int numLiveNode;
    bool firstDead;

    simsignal_t sigLifeTimeRoute;
    simsignal_t sigLifeTimePercentage;
    simsignal_t sigLifeTimeFirst;

    bool isLimit;

    int numAppSendLight;
    int numAppSendHeat;
    int numAppSendMoisture;
    int numAppSendSoil;
    simsignal_t sigNumAppSendLight;
    simsignal_t sigNumAppSendHeat;
    simsignal_t sigNumAppSendMoisture;
    simsignal_t sigNumAppSendSoil;

    int numAppRecvLight;
    int numAppRecvHeat;
    int numAppRecvMoisture;
    int numAppRecvSoil;
    simsignal_t sigNumAppRecvLight;
    simsignal_t sigNumAppRecvHeat;
    simsignal_t sigNumAppRecvMoisture;
    simsignal_t sigNumAppRecvSoil;

    double numDelayAppRecvLight;
    double numDelayAppRecvHeat;
    double numDelayAppRecvMoisture;
    double numDelayAppRecvSoil;
    simsignal_t sigNumDelayAppRecvLight;
    simsignal_t sigNumDelayAppRecvHeat;
    simsignal_t sigNumDelayAppRecvMoisture;
    simsignal_t sigNumDelayAppRecvSoil;

    /* polling for energy */
    void pollTotalSensorEnergy();
    void pollTotalSensorEnergyCount();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void finish();

  public:
    void registerStatistic(int);
    void registerStatisticDelay(int, double);
};
}
#endif
