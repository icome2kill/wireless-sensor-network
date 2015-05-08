/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to energest.h
 */

#include <energest.h>
#include <radio.h>
#include <statistic.h>
#include <ipv6.h>

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

Define_Module(Energest);

void Energest::initialize()
{
  for (int i = 0; i < ENERGEST_TYPE_MAX; i++)
  {
    this->capsuleIsActivated[i] = false;
    this->capsuleTotalTime[i] = 0;
    this->capsuleStartTime[i] = 0;
    this->power[i] = 0;
  }

  // MCU always on
//  this->power[ENERGEST_TYPE_CPU] = MSP430_POWER;
//  this->capsuleIsActivated[ENERGEST_TYPE_CPU] = true;

// total energy remaining
  this->residualEnergy = MAX_POWER;
  this->energyCap = MAX_POWER / 100;
}

void Energest::handleMessage(cMessage *msg)
{
}

void Energest::finish()
{
}

void Energest::energestOn(int type, double power)
{
  energestOff(type);

  this->capsuleStartTime[type] = simTime().dbl();
  this->capsuleIsActivated[type] = true;
  this->power[type] = power;
}

void Energest::energestOff(int type)
{
  if (this->capsuleIsActivated[type])
  {
    // turn off capsule
    this->capsuleIsActivated[type] = false;

    double consumeTime = simTime().dbl() - this->capsuleStartTime[type];

    if (DEBUG)
      ev << "Diff " << type << " :" << consumeTime << endl;

    // increase total time
    this->capsuleTotalTime[type] += consumeTime;

    // consume energy, in term off hour not second, because power is mAh
    this->residualEnergy -= consumeTime * power[type] / 3600.0;
  }

  // residual energy
  // Turn off if below critical mode
  if (this->residualEnergy <= 0)
  {
    this->residualEnergy = 0;
    this->energyLevel = 0;
    std::cout << getParentModule()->getFullName() << " DOWN" << endl;
    ((RadioDriver*) getParentModule()->getModuleByPath(".radio"))->switchOscilatorMode(POWER_DOWN);

    (check_and_cast<Statistic*>(getModuleByPath("statistics")))->registerStatistic(LIFE_TIME_FIRST_DEAD_NODE);
  }
  else
  {
    if (simulation.getModuleByPath("WSN")->par("usingELB").boolValue())
    {
      if (energyLevel != residualEnergy / energyCap)
      {
        if (check_and_cast<IPv6*>(getModuleByPath("^.net")) != NULL)
        {
          // update rank
          (check_and_cast<IPv6*>(getModuleByPath("^.net")))->rpl->rplDag->rank -= energyLevel;
          (check_and_cast<IPv6*>(getModuleByPath("^.net")))->rpl->rplDag->rank += (residualEnergy/energyCap);
//          (check_and_cast<IPv6*>(getModuleByPath("^.net")))->resetDIOTimer();
        }
      }
    }

    energyLevel = residualEnergy / energyCap;
  }
}

void Energest::update()
{
  for (int i = 0; i < ENERGEST_TYPE_MAX; i++)
  {
    bool resume = this->capsuleIsActivated[i];

    energestOff(i);

    if (resume)
      energestOn(i, this->power[i]);
  }

  // MCU always on
  this->capsuleIsActivated[ENERGEST_TYPE_CPU] = true;
}
} /* namespace wsn_energy */
