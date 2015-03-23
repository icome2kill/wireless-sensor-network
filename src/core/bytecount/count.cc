/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to count.h
 */

#include "count.h"
#include "radio.h"
#include "statistic.h"

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

Define_Module(Count);

void Count::initialize()
{
  if (getModuleByPath("^.^")->par("isPollingCount").boolValue())
  {
    this->residualEnergy = POWER;
  }
}

void Count::transmit(int numberOfBit)
{
  if (this->residualEnergy > 0)
  {
    this->residualEnergy -= numberOfBit * E_ELEC + numberOfBit * E_FS * D * D;

    if (this->residualEnergy <= 0)
    {
      // remove out-going connect
      this->residualEnergy = 0;

      check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
      LIFE_TIME_PERCENTAGE_DEAD_NODE);

      (check_and_cast<RadioDriver*>(getParentModule()->getModuleByPath(".radio")))->switchOscilatorMode(POWER_DOWN);

      char outConnectionName[20];

      int hostID = this->getParentModule()->getId();
      int serverID = simulation.getModuleByPath("server")->getId();

      sprintf(outConnectionName, "out %d to %d", hostID, serverID);

      if (this->getParentModule()->hasGate(outConnectionName)) // has connection to server
      {
        check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
        LIFE_TIME_DECREASE_SERVER_NEIGHBOR);
        if (DEBUG)
          std::cout << "Dead node while transmitting @ " << hostID << endl;
      }
    }
  }
}

void Count::receive(int numberOfBit)
{
  if (this->residualEnergy > 0)
  {
    this->residualEnergy -= numberOfBit * E_ELEC;

    if (this->residualEnergy <= 0)
    {
      // remove out-going connect
      this->residualEnergy = 0;

      check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
      LIFE_TIME_PERCENTAGE_DEAD_NODE);

      (check_and_cast<RadioDriver*>(getParentModule()->getModuleByPath(".radio")))->switchOscilatorMode(POWER_DOWN);

      char outConnectionName[20];

      int hostID = this->getParentModule()->getId();
      int serverID = simulation.getModuleByPath("server")->getId();

      sprintf(outConnectionName, "out %d to %d", hostID, serverID);

      if (this->getParentModule()->hasGate(outConnectionName)) // has connection to server
      {
        check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
        LIFE_TIME_DECREASE_SERVER_NEIGHBOR);
        if (DEBUG)
          std::cout << "Dead node receives @ " << hostID << endl;
      }
    }
  }
}

} //namespace
