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

package wsn_energy.util.statistic;

//
// Statistics Collector
//
simple Statistic
{
    parameters:
        @signal[networkEnergyCount](type="int");
        @statistic[networkEnergyCount](title="Node energy (count)"; record=vector);
        @signal[sensorEnergyCount](type="int");
        @statistic[sensorEnergyCount](title="Sensor energy (count)"; record=vector);

        @signal[networkEnergy](type="double");
        @statistic[networkEnergy](title="Node energy"; record=vector);
        @signal[sensorEnergy](type="double");
        @statistic[sensorEnergy](title="Sensor energy"; record=vector);
        @signal[sensorEnergyLevel](type="int");
        @statistic[sensorEnergyLevel](title="Sensor energy (level)"; record=vector);

        @signal[totalEnergy](type="double");
        @statistic[totalEnergy](title="Total energy"; record=last);

        @signal[totalDelayApp](type="double");
        @statistic[totalDelayApp](title="Total delay (app): "; record=last);
        @signal[totalDelayNet](type="double");
        @statistic[totalDelayNet](title="Total delay (net): "; record=last);

        @signal[appSend](type="int");
        @signal[appRecv](type="int");
        @signal[netSend](type="int");
        @signal[netRecv](type="int");
        @signal[macSend](type="int");
        @signal[macRecv](type="int");
        @signal[radioSend](type="int");
        @signal[radioRecv](type="int");
        @statistic[appSend](title="Number of app layer send: "; record=last);
        @statistic[appRecv](title="Number of app layer recv: "; record=last);
        @statistic[netSend](title="Number of net layer send: "; record=last);
        @statistic[netRecv](title="Number of net layer recv: "; record=last);
        @statistic[macSend](title="Number of mac layer send: "; record=last);
        @statistic[macRecv](title="Number of mac layer recv: "; record=last);
        @statistic[radioSend](title="Number of radio layer send: "; record=last);
        @statistic[radioRecv](title="Number of radio layer recv: "; record=last);

        @signal[timeIdle](type="double");
        @signal[timeTrans](type="double");
        @signal[timeListen](type="double");
        @statistic[timeIdle](title="Time idling: "; record=last);
        @statistic[timeTrans](title="Time transmitting: "; record=last);
        @statistic[timeListen](title="Time listening: "; record=last);

        @signal[dioSent](type="int");
        @signal[disSent](type="int");
        @signal[ipInter](type="int");
        @signal[ipTrans](type="int");
        @statistic[dioSent](title="Number of DIO  send       : "; record=last);
        @statistic[disSent](title="Number of DIS  send       : "; record=last);
        @statistic[ipInter](title="Number of ip forwarding   : "; record=last);
        @statistic[ipTrans](title="Number of ip transmitting : "; record=last);

        @signal[lifeTime](type="double");
        @signal[lifeTimePercentage](type="double");
        @signal[lifeTimeFirst](type="double");
        @statistic[lifeTimeRoute](title="Network life time (route): "; record=last);
        @statistic[lifeTimePercentage](title="Network life time (percentage): "; record=last);
        @statistic[lifeTimeFirst](title="Network life time (first): "; record=last);

        @signal[appSendLight](type="int");
        @signal[appRecvLight](type="int");
        @signal[appRecvLightDelay](type="double");
        @statistic[appSendLight](title="Number of light data send: "; record=last);
        @statistic[appRecvLight](title="Number of light data recv: "; record=last);
        @statistic[appRecvLightDelay](title="Total delay (in second) of received light data: "; record=last);
        @signal[appSendTemperature](type="int");
        @signal[appRecvTemperature](type="int");
        @signal[appRecvTemperatureDelay](type="double");
        @statistic[appSendTemperature](title="Number of temperature data send: "; record=last);
        @statistic[appRecvTemperature](title="Number of temperature data recv: "; record=last);
        @statistic[appRecvTemperatureDelay](title="Total delay (in second) of received temperature data: "; record=last);
        @signal[appSendMoisture](type="int");
        @signal[appRecvMoisture](type="int");
        @signal[appRecvMoistureDelay](type="double");
        @statistic[appSendMoisture](title="Number of moisture data send: "; record=last);
        @statistic[appRecvMoisture](title="Number of moisture data recv: "; record=last);
        @statistic[appRecvMoistureDelay](title="Total delay (in second) of received moisture data: "; record=last);
        @signal[appSendSoil](type="int");
        @signal[appRecvSoil](type="int");
        @signal[appRecvSoilDelay](type="double");
        @statistic[appSendSoil](title="Number of Soil data send: "; record=last);
        @statistic[appRecvSoil](title="Number of Soil data recv: "; record=last);
        @statistic[appRecvSoilDelay](title="Total delay (in second) of received Soil data: "; record=last);

        @display("p=-10,40;i=block/table2");
}
