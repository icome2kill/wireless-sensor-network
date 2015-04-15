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

package wsn_energy.mote;

import wsn_energy.apps.iApp;
import wsn_energy.core.transport.iTransport;
import wsn_energy.core.net.iNet;
import wsn_energy.core.mac.iMAC;
import wsn_energy.core.rdc.iRDC;
import wsn_energy.core.radio.iRadio;
import wsn_energy.core.energest.Energest;
import wsn_energy.core.bytecount.Count;

//
// TODO auto-generated type
//
module ClientMote
{
    parameters:
        string appType;
        string traType;
        string netType;
        string macType;
        string rdcType;
        string radioType;

        int axisX @unit(m);
        int axisY @unit(m);

        @display("p=$axisX,$axisY;i=misc/node2;is=vs;t=Node");

    submodules:
        energest: Energest {
            @display("p=50,50");
        }
        count: Count {
            @display("p=50,125");
        }
        app: <appType> like iApp {
            @display("p=150,50");
        }
        tra: <traType> like iTransport {
            @display("p=150,150");
        }
        net: <netType> like iNet {
            @display("p=150,250");
        }
        mac: <macType> like iMAC {
            @display("p=150,350");
        }
        rdc: <rdcType> like iRDC {
            @display("p=150,450");
        }
        radio: <radioType> like iRadio {
            parameters:
                @display("p=150,550");
        }
    connections allowunconnected:
        app.lowerOut --> tra.upperIn;
        app.lowerIn <-- tra.upperOut;

        tra.lowerOut --> net.upperIn;
        tra.lowerIn <-- net.upperOut;

        net.lowerOut --> mac.upperIn;
        net.lowerIn <-- mac.upperOut;

        mac.lowerOut --> rdc.upperIn;
        mac.lowerIn <-- rdc.upperOut;

        rdc.lowerOut --> radio.upperIn;
        rdc.lowerIn <-- radio.upperOut;
}
