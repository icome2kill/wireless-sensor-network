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

package wsn_energy.core.radio.cc2420;

import wsn_energy.core.radio.iRadio;

//
// TODO auto-generated type
//
simple cc2420 like iRadio
{
    parameters:
        @class("cc2420");
        @display("i=block/mac");

        double trRange @unit(m) = default(0);
        double coRange @unit(m) = default(0);

    gates:
        input upperIn;
        output upperOut;

        input radioIn @directin;
}
