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

package wsn_energy.simulations;

import wsn_energy.mote.ClientMote;
import wsn_energy.mote.ServerMote;
import wsn_energy.util.world.World;
import wsn_energy.util.statistic.Statistic;

//
// Sample network, consisting of a source and a sink.
//
network WSN
{
    parameters:
        int timeLimit;
        int setupDelay;

        int topology;

		bool usingRPL;
        bool usingFLR;
        bool usingELB;
        bool usingHDC;

        int width @unit(m);
        int height @unit(m);

        int numberClient;

        int serverX @unit(m);
        int serverY @unit(m);

        int scheme;
        int rand;

        bool isPollingCount;
        bool isPolling;
        double polling;

        int ssRange @unit(m);
        
        int lightSensingDelay;
        int temperatureSensingDelayHigh;
        int temperatureSensingDelayLow;
        int moistureSensingDelay;
        int soilSensingDelayHigh;
        int soilSensingDelayLow;

        @display("bgs=6,m;bgb=$width,$height,#C6C6FF,#0000FF,2");

    submodules:
        server: ServerMote {
            parameters:
                axisX = serverX;
                axisY = serverY;
        }
        client[numberClient]: ClientMote {
            parameters:
                axisX = 0;
                axisY = 0;
        }
        statistic: Statistic;
        world: World;
    connections allowunconnected:
}
