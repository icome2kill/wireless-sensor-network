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

#include "cc2420.h"

#include "world.h"
#include "statistic.h"
#include "energest.h"

#ifndef  DEBUG
#define  DEBUG 1
#endif

namespace wsn_energy {

Define_Module(cc2420);

double cc2420::intervalCCA()
{
  return (12 + 8) * SYMBOL; // 12 symbols switch mode + 8 symbols sample
}

double cc2420::getTxPower()
{
  return txPower * SUPPLY_VOLTAGE;
}

double cc2420::getRxPower()
{
  return RXPOWER_CURRENT * SUPPLY_VOLTAGE;
}

double cc2420::getIdPower()
{
  return IDPOWER_CURRENT * SUPPLY_VOLTAGE;
}

}
/* namespace wsn_energy */
