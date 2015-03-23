package wsn_energy.simulations;

import wsn_energy.mote.ClientMote;
import wsn_energy.mote.ServerMote;
import wsn_energy.util.world.World;
import wsn_energy.util.statistic.Statistic;

//
// Sample network, consisting of a source and a sink.
//
network RPL
{
    parameters:
        int width @unit(m);
        int height @unit(m);
        int ssRange @unit(m);

        bool isPolling;
        bool isPollingCount;

        int numberClient;

        int topology;

		bool usingRPL;
        bool usingFLR;
        bool usingELB;
        bool usingHDC;

        int scheme;
        int rand;

        @display("bgs=6,m;bgb=$width,$height,#C6C6FF,#0000FF,2");
    submodules:
        server: ServerMote {
            parameters:
                axisX = 55m;
                axisY = 10m;
        }
        client[numberClient]: ClientMote{
            parameters:
                axisX = 0m;
                axisY = 0m;
        }
        world: World;
    connections allowunconnected:
}
