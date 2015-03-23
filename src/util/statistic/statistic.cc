/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to statistic.h
 */

#include "statistic.h"
#include "energest.h"
#include "count.h"
#include "ipv6.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cconfiguration.h>

namespace wsn_energy {

Define_Module(Statistic);

void Statistic::initialize() {
    polling = new cMessage();
    pollingCount = new cMessage();

    // Initialize statistics number
    numNetworkEnergyCount = 0;
    numSensorEnergyCount = 0;
    numSensorEnergyLevel = 0;
    numNetworkEnergy = 0;
    numTotalEnergy = 0;
    numTotalDelayApp = 0;
    numTotalDelayNet = 0;
    numAppSend = 0;
    numAppRecv = 0;
    numNetSend = 0;
    numNetRecv = 0;
    numMacSend = 0;
    numMacRecv = 0;
    numRadioSend = 0;
    numRadioRecv = 0;
    timeIdle = 0;
    timeListen = 0;
    timeTrans = 0;
    numDIOsent = 0;
    numDISsent = 0;
    numIPinter = 0;
    numIPtrans = 0;

    numAppSendLight = 0;
    numAppSendHeat = 0;
    numAppSendMoisture = 0;
    numAppSendSoil = 0;

    numAppRecvLight = 0;
    numAppRecvHeat = 0;
    numAppRecvMoisture = 0;
    numAppRecvSoil = 0;

    numDelayAppRecvLight = 0;
    numDelayAppRecvHeat = 0;
    numDelayAppRecvMoisture = 0;
    numDelayAppRecvSoil = 0;

    numLiveNode = getParentModule()->par("numberClient").doubleValue();
    firstDead = false;

    // register signal
    sigNetworkEnergyCount = registerSignal("networkEnergyCount");
    sigSensorEnergyCount = registerSignal("sensorEnergyCount");
    sigNetworkEnergy = registerSignal("networkEnergy");
    sigSensorEnergy = registerSignal("sensorEnergy");
    sigSensorEnergyLevel = registerSignal("sensorEnergyLevel");
    sigTotalEnergy = registerSignal("totalEnergy");
    sigTotalDelayApp = registerSignal("totalDelayApp");
    sigTotalDelayNet = registerSignal("totalDelayNet");
    sigAppSend = registerSignal("appSend");
    sigAppRecv = registerSignal("appRecv");
    sigNetSend = registerSignal("netSend");
    sigNetRecv = registerSignal("netRecv");
    sigMacSend = registerSignal("macSend");
    sigMacRecv = registerSignal("macRecv");
    sigRadioSend = registerSignal("radioSend");
    sigRadioRecv = registerSignal("radioRecv");
    sigTimeIdle = registerSignal("timeIdle");
    sigTimeListen = registerSignal("timeListen");
    sigTimeTrans = registerSignal("timeTrans");
    sigNumDIOsent = registerSignal("dioSent");
    sigNumDISsent = registerSignal("disSent");
    sigNumIPinter = registerSignal("ipInter");
    signumIPtrans = registerSignal("ipTrans");
    sigLifeTimeRoute = registerSignal("lifeTimeRoute");
    sigLifeTimePercentage = registerSignal("lifeTimePercentage");
    sigLifeTimeFirst = registerSignal("lifeTimeFirst");

    sigNumAppSendLight = registerSignal("appSendLight");
    sigNumAppSendHeat = registerSignal("appSendHeat");
    sigNumAppSendMoisture = registerSignal("appSendMoisture");
    sigNumAppSendSoil = registerSignal("appSendSoil");

    sigNumAppRecvLight = registerSignal("appRecvLight");
    sigNumAppRecvHeat = registerSignal("appRecvHeat");
    sigNumAppRecvMoisture = registerSignal("appRecvMoisture");
    sigNumAppRecvSoil = registerSignal("appRecvSoil");

    sigNumDelayAppRecvLight = registerSignal("appRecvLightDelay");
    sigNumDelayAppRecvHeat = registerSignal("appRecvHeatDelay");
    sigNumDelayAppRecvMoisture = registerSignal("appRecvMoistureDelay");
    sigNumDelayAppRecvSoil = registerSignal("appRecvSoilDelay");

    // start polling
    if (simulation.getModuleByPath("WSN") != NULL) {
        if (getParentModule()->par("isPolling").boolValue())
            scheduleAt(simTime(), polling);

        if (getParentModule()->par("isPollingCount").boolValue())
            scheduleAt(
                    simTime() + getParentModule()->par("polling").doubleValue(),
                    pollingCount);
    }

    isLimit = true;
}

void Statistic::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        if (msg == polling) {
            if (simTime() + getParentModule()->par("polling")
                    < getModuleByPath("^")->par("timeLimit").doubleValue()) {
                pollTotalSensorEnergy();
                scheduleAt(
                        simTime()
                                + getParentModule()->par("polling").doubleValue(),
                        polling);
            } else {
                if (isLimit) {
                    isLimit = false;

                    // Power status of remaining sensor(s)
                    cModule *wsn = getModuleByPath("^");
                    int numberClient = wsn->par("numberClient").longValue();

                    for (int i = 0; i < numberClient; i++) {
                        numSensorEnergy = (check_and_cast<Energest*>(
                                wsn->getSubmodule("client", i)->getSubmodule(
                                        "energest")))->residualEnergy;

                        numTotalEnergy += numSensorEnergy;

                        // % duty cycling
                        timeTrans +=
                                (check_and_cast<Energest*>(
                                        wsn->getSubmodule("client", i)->getSubmodule(
                                                "energest")))->capsuleTotalTime[ENERGEST_TYPE_TRANSMIT];
                        timeListen +=
                                (check_and_cast<Energest*>(
                                        wsn->getSubmodule("client", i)->getSubmodule(
                                                "energest")))->capsuleTotalTime[ENERGEST_TYPE_LISTEN];
                        timeIdle +=
                                (check_and_cast<Energest*>(
                                        wsn->getSubmodule("client", i)->getSubmodule(
                                                "energest")))->capsuleTotalTime[ENERGEST_TYPE_IDLE];

                        // residual energy
                        if (getParentModule()->par("isPollingCount").boolValue()) {
                            numSensorEnergyCount =
                                    check_and_cast<Count*>(
                                            wsn->getSubmodule("client", i)->getSubmodule(
                                                    "count"))->residualEnergy;
                            emit(sigSensorEnergyCount, numSensorEnergyCount);
                        }

                        if (getParentModule()->par("isPolling").boolValue()) {
                            numSensorEnergy =
                                    check_and_cast<Energest*>(
                                            wsn->getSubmodule("client", i)->getSubmodule(
                                                    "energest"))->residualEnergy;
                            emit(sigSensorEnergy, numSensorEnergy);
                        }

                        numSensorEnergyLevel = check_and_cast<Energest*>(
                                wsn->getSubmodule("client", i)->getSubmodule(
                                        "energest"))->energyLevel;
                        emit(sigSensorEnergyLevel, numSensorEnergyLevel);
                    }

                    emit(sigTimeIdle, timeIdle);
                    emit(sigTimeTrans, timeTrans);
                    emit(sigTimeListen, timeListen);
                    emit(sigTotalEnergy, numTotalEnergy);
                }
            }
        } else if (msg == pollingCount) {
            if (simTime() + getParentModule()->par("polling")
                    < getModuleByPath("^")->par("timeLimit").doubleValue()) {
                pollTotalSensorEnergyCount();
                scheduleAt(
                        simTime()
                                + getParentModule()->par("polling").doubleValue(),
                        pollingCount);
            }
        }
    }
}

void Statistic::finish() {
    // poll last time
//  pollTotalSensorEnergy();
//  pollTotalSensorEnergyCount();

    cancelAndDelete(polling);
    cancelAndDelete(pollingCount);
}

void Statistic::pollTotalSensorEnergyCount() {
    if (getParentModule()->par("isPollingCount").boolValue()) {

        cModule *wsn = getModuleByPath("WSN");
        int numberClient = wsn->par("numberClient").longValue();

        numNetworkEnergyCount = 0.0;

        for (int i = 0; i < numberClient; i++) {
            numNetworkEnergyCount +=
                    (check_and_cast<Count*>(
                            wsn->getSubmodule("client", i)->getSubmodule(
                                    "count")))->residualEnergy;
        }

        emit(sigNetworkEnergyCount, numNetworkEnergyCount);
    }
}

void Statistic::pollTotalSensorEnergy() {
//  if (getParentModule()->par("isPolling").boolValue())
//  {
//
//    cModule *wsn = getModuleByPath("WSN");
//    int numberClient = wsn->par("numberClient").longValue();
//
//    numNetworkEnergy = 0.0;
//
//    for (int i = 0; i < numberClient; i++)
//    {
//      (check_and_cast<Energest*>(wsn->getSubmodule("client", i)->getSubmodule("energest")))->update();
//      numNetworkEnergy +=
//          (check_and_cast<Energest*>(wsn->getSubmodule("client", i)->getSubmodule("energest")))->residualEnergy;
//    }
//
//    emit(sigNetworkEnergy, numNetworkEnergy);
//  }
}

void Statistic::registerStatistic(int type) {
    Enter_Method_Silent
    ("registerStatistic");

    if (type == LIFE_TIME_FIRST_DEAD_NODE) {
        if (!firstDead) {
            firstDead = true;
            emit(sigLifeTimeFirst, simTime().dbl());

            // Stop simulation when first node dead appears
            endSimulation();
        }
    } else if (simTime().dbl()
            > getParentModule()->par("timeLimit").doubleValue())
        ;
    else
        switch (type) {
        case APP_SEND:
            emit(sigAppSend, ++numAppSend);
            break;
        case APP_RECV:
            emit(sigAppRecv, ++numAppRecv);
            break;
        case NET_SEND:
            emit(sigNetSend, ++numNetSend);
            break;
        case NET_RECV:
            emit(sigNetRecv, ++numNetRecv);
            break;
        case MAC_SEND:
            emit(sigMacSend, ++numMacSend);
            break;
        case MAC_RECV:
            emit(sigMacRecv, ++numMacRecv);
            break;
        case RADIO_SEND:
            emit(sigRadioSend, ++numRadioSend);
            break;
        case RADIO_RECV:
            emit(sigRadioRecv, ++numRadioRecv);
            break;
        case DIO_SENT:
            emit(sigNumDIOsent, ++numDIOsent);
            break;
        case DIS_SENT:
            emit(sigNumDISsent, ++numDISsent);
            break;
        case IP_INTER:
            emit(sigNumIPinter, ++numIPinter);
            break;
        case IP_TRANS:
            emit(signumIPtrans, ++numIPtrans);
            break;
        case APP_SEND_LIGHT:
            emit(sigNumAppSendLight, ++numAppSendLight);
            break;
        case APP_SEND_HEAT:
            emit(sigNumAppSendHeat, ++numAppSendHeat);
            break;
        case APP_SEND_MOISTURE:
            emit(sigNumAppSendMoisture, ++numAppSendMoisture);
            break;
        case APP_SEND_SOIL:
            emit(sigNumAppSendSoil, ++numAppSendSoil);
            break;
        case APP_RECV_LIGHT:
            emit(sigNumAppRecvLight, ++numAppRecvLight);
            break;
        case APP_RECV_HEAT:
            emit(sigNumAppRecvHeat, ++numAppRecvHeat);
            break;
        case APP_RECV_MOISTURE:
            emit(sigNumAppRecvMoisture, ++numAppRecvMoisture);
            break;
        case APP_RECV_SOIL:
            emit(sigNumAppRecvSoil, ++numAppRecvSoil);
            break;
//    case LIFE_TIME_INCREASE_SERVER_NEIGHBOR:
//      this->numServerNeighbor++;
//      std::cout << "Server neighbor: " << numServerNeighbor << endl;
//      break;
//    case LIFE_TIME_DECREASE_SERVER_NEIGHBOR:
//      this->numServerNeighbor--;
//      if (this->numServerNeighbor == 0)
//        emit(sigLifeTimeRoute, simTime().dbl());
//      break;
//    case LIFE_TIME_PERCENTAGE_DEAD_NODE:
//      this->numLiveNode--;
//      // Hard coded number
//      if (this->numLiveNode < 137 && this->numLiveNode > -1) // 70 % deadnode -> life time, -1 to unregister
//      {
//        emit(sigLifeTimePercentage, simTime().dbl());
//        this->numLiveNode = -1;
//      }
//      break;
        }
}

void Statistic::registerStatisticDelay(int type, double delayTime) {
    Enter_Method_Silent
    ("registerStatisticDelay");

    if (simTime().dbl() > getParentModule()->par("timeLimit").doubleValue())
        ;
    else
        switch (type) {
        case DELAY_APP_LAYER: /* end to end delay */
            numTotalDelayApp += delayTime;
            emit(sigTotalDelayApp, numTotalDelayApp);
            break;
        case DELAY_NET_LAYER: /* hop to hop delay */
            numTotalDelayNet += delayTime;
            emit(sigTotalDelayNet, numTotalDelayNet);
            break;
        case APP_RECV_LIGHT_DELAY:
            numDelayAppRecvLight += delayTime;
            emit(sigNumDelayAppRecvLight, numDelayAppRecvLight);
            break;
        case APP_RECV_HEAT_DELAY:
            numDelayAppRecvHeat += delayTime;
            emit(sigNumDelayAppRecvHeat, numDelayAppRecvHeat);
            break;
        case APP_RECV_MOISTURE_DELAY:
            numDelayAppRecvMoisture += delayTime;
            emit(sigNumDelayAppRecvMoisture, numDelayAppRecvMoisture);
            break;
        case APP_RECV_SOIL_DELAY:
            numDelayAppRecvSoil += delayTime;
            emit(sigNumDelayAppRecvSoil, numDelayAppRecvSoil);
            break;
        }
}
}
