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

#ifndef CC2420_H_
#define CC2420_H_

#include "radio.h"

namespace wsn_energy {

class cc2420 : public RadioDriver
{
  public:
    virtual double intervalCCA();

    virtual double getTxPower();
    virtual double getRxPower();
    virtual double getIdPower();
};

} /* namespace wsn_energy */

#endif /* CC2420_H_ */
