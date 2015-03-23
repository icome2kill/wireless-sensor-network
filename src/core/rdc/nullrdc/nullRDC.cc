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

#include "nullRDC.h"
#include "packet_m.h"

#ifndef  DEBUG
#define DEBUG 1
#endif

namespace wsn_energy {

Define_Module(nullRDC);

void nullRDC::selfProcess(cPacket*) {
    // TODO
}

/* command from MAC */
void nullRDC::beginTransmitting(int command) {
    // TODO
    return;
}

/* send packet */
void nullRDC::transmitFrame() {
    // TODO
    return;
}

/* receive success from PHY */
void nullRDC::receiveFrame(Frame*) {
    // TODO
    return;
}

} /* namespace wsn_energy */
