/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: Distributed client, collect data and forward to server
 */

#ifndef __WSN_ENERGY_SOURCE_H
#define __WSN_ENERGY_SOURCE_H

#include <myModule.h>
#include <macAddress.h>
#include <ipAddress.h>
#include <string>

#ifndef UDP_PORT
#define UDP_PORT
#define UDP_SERVER_PORT 5678 // UDP port
#define UDP_CLIENT_PORT 8765 // UDP port
#endif

using namespace std;

namespace wsn_energy {

class Client : public myModule
{
  private:
    int packetNumber;
    IpAddress* serverAddress;
    std::vector<std::string> dataQueue;

    unsigned int soilCount;
    unsigned int moistureCount;
    unsigned int temperatureCount;
    unsigned int lightCount;
//    std::queue<string> msgQueue;

    void sendData();
    void newData();
    void initSensors(bool);
    void sendData(char *);
    void sendData(char *, int);
    void sendDataReal();

  protected:
    void initialize();

  public:
    MacAddress* macAddress;
    IpAddress* ipAddress;

    void processSelfMessage(cPacket*);
    void processUpperLayerMessage(cPacket*);
    void processLowerLayerMessage(cPacket*);

    // Send message API using UDP/IP
    void sendMessage(char*, int, int, int);
};

}
;
// namespace

#endif
