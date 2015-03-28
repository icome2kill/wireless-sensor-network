/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to client.h
 */

#include <fstream>
#include "client.h"
#include "radio.h"
#include "statistic.h"
#include "data_m.h"

// define number of packet each sensor need to send
//#define MAX 60
//#define MAX 1

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

namespace wsn_energy {

Define_Module(Client);

void Client::initialize() {
    // set global address
    // simulate the pseudo-assigned MAC and IPv6 address creation
//    this->msgQueue = new std::queue();

    // create MAC
    this->macAddress = new MacAddress(getId());

    // create self IPv6 sddress
    this->ipAddress = new IpAddress(this->macAddress);

    // set gloabl server address
    // network address aaaa::/64
    // suppose it is a MAC-48 from 64 bit by putting ff::fe to midle
    // server address aaaa::ff::fe:1
    this->serverAddress = new IpAddress(170, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            255, 254, 0, 0, 1);

    if (DEBUG) {
        std::cout << this->getFullPath() << " has mac address ";
        this->macAddress->print();
        std::cout << this->getFullPath()
                << " has tentative link-local address ";
        this->ipAddress->print();
        std::cout << endl;
    }

    this->packetNumber = 0;

    /* Contiki test scheme */
    switch ((int) getModuleByPath("^.^")->par("scheme").doubleValue()) {
    case 1: /* one manual event */
    {
        if (this->getParentModule()->getId()
                == simulation.getModuleByPath("client[8]")->getId())
            selfTimer(
                    getModuleByPath("^.^")->par("setupDelay").doubleValue()
                            + 10, APP_SENSING_FLAG);

        if (this->getParentModule()->getId()
                == simulation.getModuleByPath("client[8]")->getId())
            selfTimer(
                    getModuleByPath("^.^")->par("setupDelay").doubleValue()
                            + 20, APP_SENSING_FLAG);

        if (this->getParentModule()->getId()
                == simulation.getModuleByPath("client[8]")->getId())
            selfTimer(
                    getModuleByPath("^.^")->par("setupDelay").doubleValue()
                            + 30, APP_SENSING_FLAG);

        break;
    } /* one event */

    case 2: /* ignite periodically */
    {
        selfTimer(getModuleByPath("^.^")->par("setupDelay").doubleValue(),
                RPL_SET_UP_DELAY);

        break;
    } /* ignite periodically */

    case 3: /* RPL test */
    {
        // TODO
        break;
    }/* RPL test */

    case 4: {
        // Send data periodically according to requirement. (High frequency)
        initSensors(true);
        break;
    }
    case 5: {
        initSensors(false);
        break;
    }
    default:
        if (DEBUG)
            ev << "Just construct " << endl;
        break;
    }

    if (getParentModule() != NULL) {
        std::ofstream myfile;
        char myfilename[100];

        sprintf(myfilename, "client_data/id_%s_data_light.txt",
                getParentModule()->getFullName());
        myfile.open(myfilename);
        myfile << "light" << "\n";
        myfile.close();

        sprintf(myfilename, "client_data/id_%s_data_temperature.txt",
                getParentModule()->getFullName());
        myfile.open(myfilename);
        myfile << "temperature (C)" << "\n";
        myfile.close();

        sprintf(myfilename, "client_data/id_%s_data_moisture.txt",
                getParentModule()->getFullName());
        myfile.open(myfilename);
        myfile << "moisture (%)" << "\n";
        myfile.close();

        sprintf(myfilename, "client_data/id_%s_data_soil.txt",
                getParentModule()->getFullName());
        myfile.open(myfilename);
        myfile << "PH, moisture" << "\n";
        myfile.close();
    }
}

void Client::initSensors(bool isHighFreq) {
    if (DEBUG)
        std::cout << this->getFullPath() << " init sensors" << endl;
    double setupDelay = getModuleByPath("^.^")->par("setupDelay").doubleValue();
    selfTimer(
            setupDelay
                    + getModuleByPath("^.^")->par("lightSensingDelay").doubleValue(),
            APP_SEND_LIGHT_DATA);
    selfTimer(
            setupDelay
                    + getModuleByPath("^.^")->par("moistureSensingDelay").doubleValue(),
            APP_SEND_MOISTURE_DATA);
    if (isHighFreq) {
        selfTimer(
                setupDelay
                        + getModuleByPath("^.^")->par(
                                "temperatureSensingDelayHigh").doubleValue(),
                APP_SEND_TEMPERATURE_DATA_HIGH);
        selfTimer(
                setupDelay
                        + getModuleByPath("^.^")->par("soilSensingDelayHigh").doubleValue(),
                APP_SEND_SOIL_DATA_HIGH);
    } else {
        selfTimer(
                setupDelay
                        + getModuleByPath("^.^")->par(
                                "temperatureSensingDelayLow").doubleValue(),
                APP_SEND_TEMPERATURE_DATA_LOW);
        selfTimer(
                setupDelay
                        + getModuleByPath("^.^")->par("soilSensingDelayLow").doubleValue(),
                APP_SEND_SOIL_DATA_LOW);
    }
}

void Client::processSelfMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case COMMAND: /* Command */
    {
        switch (check_and_cast<Command*>(packet)->getNote()) {
        case RPL_SET_UP_DELAY: /* set up delay */
        {
            newData();
            break;
        }/* set up delay*/

        case APP_SENSING_FLAG: /* new data */
        {
            // Timer for next message
            if ((int) getModuleByPath("^.^")->par("scheme").doubleValue()
                    == 2) {
#ifdef MAX
                if (++this->packetNumber < MAX) // control maximum number
#else
                ++this->packetNumber;
#endif
                newData();
            }

            break; /* new data */
        }

        case APP_READY_TO_SEND: /* ready to send */
        {
            // begin send data
            sendData();
            break;
        } /* ready to send */
        case APP_SEND_LIGHT_DATA: {
            sendData("1 Light data", APP_SEND_LIGHT);
            selfTimer(
                    getModuleByPath("^.^")->par("lightSensingDelay").doubleValue(),
                    APP_SEND_LIGHT_DATA);
            break;
        }
        case APP_SEND_TEMPERATURE_DATA_HIGH: {
            sendData("2 Temperature data", APP_SEND_TEMPERATURE);
            selfTimer(
                    getModuleByPath("^.^")->par("temperatureSensingDelayHigh").doubleValue(),
                    APP_SEND_TEMPERATURE_DATA_HIGH);
            break;
        }
        case APP_SEND_TEMPERATURE_DATA_LOW: {
            sendData("2 Temperature data", APP_SEND_TEMPERATURE);
            selfTimer(
                    getModuleByPath("^.^")->par("temperatureSensingDelayLow").doubleValue(),
                    APP_SEND_TEMPERATURE_DATA_LOW);
            break;
        }
        case APP_SEND_MOISTURE_DATA: {
            sendData("3 Moisture data", APP_SEND_MOISTURE);
            selfTimer(
                    getModuleByPath("^.^")->par("moistureSensingDelay").doubleValue(),
                    APP_SEND_MOISTURE_DATA);
            break;
        }
        case APP_SEND_SOIL_DATA_HIGH: {
            sendData("4 SOIL data", APP_SEND_SOIL);
            selfTimer(
                    getModuleByPath("^.^")->par("soilSensingDelayHigh").doubleValue(),
                    APP_SEND_SOIL_DATA_HIGH);
            break;
        }
        case APP_SEND_SOIL_DATA_LOW: {
            sendData("4 SOIL data", APP_SEND_SOIL);
            selfTimer(
                    getModuleByPath("^.^")->par("soilSensingDelayHigh").doubleValue(),
                    APP_SEND_SOIL_DATA_LOW);
            break;
        }
        case APP_SEND_DATA_REAL: {
            sendDataReal();
        }
        default:
            ev << "Unknown command" << endl;
            break;
        }
        delete packet; // done command
        break;
        /* Command */
    }

    default:
        delete packet;
        ev << "Unknown kind" << endl;
        break;
    }
}

void Client::processUpperLayerMessage(cPacket*) {
    /* Highest layer */
    return;
}

void Client::processLowerLayerMessage(cPacket*) {
}

/*
 * Start timer to begin to collect data
 */
void Client::newData() {
    int sendInterval = 55; // seconds
    int restPeriod = 10; // seconds

    // avoid immediately sending + simulate not-synchronized clock
    double time = 0;

//  if (simTime() + sendInterval + restPeriod < getModuleByPath("^.^")->par("timeLimit").doubleValue())
    selfTimer(sendInterval + restPeriod, APP_SENSING_FLAG);

    if (getModuleByPath("^.^")->par("rand").doubleValue() == 0)
        time = (rand() % 10000) / 10000.0 * sendInterval;
    else if (getModuleByPath("^.^")->par("rand").doubleValue() == 1)
        time = intuniform(0, 10000) / 10000.0 * sendInterval;

    if (DEBUG)
        this->getParentModule()->bubble("Data");

//  if (simTime().dbl() + sendInterval < getModuleByPath("^.^")->par("timeLimit").doubleValue())
    selfTimer(time, APP_READY_TO_SEND);
}

/*
 * Collect data from outside world and send toward server
 */
void Client::sendData() {
    // create data to send
    char buf[30];
    int len = sprintf(buf, "Hello %d from %s", packetNumber,
            getParentModule()->getFullName());

    // hack port, address
    int destinationPort = UDP_SERVER_PORT;
    int destinationAddress =
    simulation.getModuleByPath("server.net")->getId();

    sendMessage(buf, len, destinationPort, destinationAddress);

    /* End to end statistics */
    (check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
    APP_SEND));
}

void Client::sendData(char* message, int type) {

    char buf[100] = { 0 };
    char data[100] = { 0 };
    char myfilename[100] = { 0 };
    int len = 0;

    // hack port, address
    int destinationPort = UDP_SERVER_PORT;
    int destinationAddress = simulation.getModuleByPath("server.net")->getId();

    if (type != APP_SEND) {
        std::ofstream myfile;
        switch (type) {
        case APP_SEND_LIGHT:
            buf[0] = '\0';
            data[0] = '\0';
            myfilename[0] = '\0';

            sprintf(data, "1/%d", rand() % 200 + 4300);
            sprintf(myfilename, "client_data/id_%s_data_light.txt",
                    getParentModule()->getFullName());

            myfile.open(myfilename, std::ios::app);
            break;
        case APP_SEND_TEMPERATURE:
            buf[0] = '\0';
            data[0] = '\0';
            myfilename[0] = '\0';

            sprintf(data, "2/%d", rand() % 200 + 1900);
            sprintf(myfilename, "client_data/id_%s_data_temperature.txt",
                    getParentModule()->getFullName());

            myfile.open(myfilename, std::ios::app);
            break;
        case APP_SEND_MOISTURE:
            buf[0] = '\0';
            data[0] = '\0';
            myfilename[0] = '\0';

            sprintf(data, "3/%d", rand() % 200 + 3700);
            sprintf(myfilename, "client_data/id_%s_data_moisture.txt",
                    getParentModule()->getFullName());

            myfile.open(myfilename, std::ios::app);
            break;
        case APP_SEND_SOIL:
            buf[0] = '\0';
            data[0] = '\0';
            myfilename[0] = '\0';

            sprintf(data, "4/%d, %d", rand() % 20 + 60, rand() % 200 + 5000);
            sprintf(myfilename, "client_data/id_%s_data_soil.txt",
                    getParentModule()->getFullName());

            myfile.open(myfilename, std::ios::app);
            break;
        }

        len = sprintf(buf, "%s|%s", getParentModule()->getFullName(), data);

        string data2 = data;
        myfile << simTime().inUnit(SIMTIME_MS);
        myfile << ", ";
        myfile << data2.substr(2, data2.size());
        myfile << "\n";
        myfile.close();
    } else {
        buf[0] = '\0';
        len = sprintf(buf, message);
    }
//    len = sprintf(buf, message);
    if (getModuleByPath("^.^")->par("usingMsgQueue")) {
        this->dataQueue.push_back(data);
        selfTimer(0.5f, APP_SEND_DATA_REAL);
    } else {
        sendMessage(buf, len, destinationPort, destinationAddress);

        if (DEBUG) {
            std::cout << "Sending data " << buf << endl;
            this->bubble(message);
        }
    }

    /* End to end statistics */
    (check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
            type));
    (check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
    APP_SEND));
}

void Client::sendDataReal() {
    if (this->dataQueue.size() == 0) {
        return;
    }

    std::string message = getParentModule()->getFullName();
    message += "|";
    for (unsigned int i = 0; i < this->dataQueue.size(); i++) {
        string data = this->dataQueue.at(i);
        message += data + "|";
    }
    message = message.substr(0, message.size() - 1);

    char buf[128] = { 0 };
    int len = sprintf(buf, message.c_str());
    int destinationPort = UDP_SERVER_PORT;
    int destinationAddress = simulation.getModuleByPath("server.net")->getId();
    sendMessage(buf, len, destinationPort, destinationAddress);

    if (DEBUG) {
        std::cout << "Sending data " << buf << endl;
    }

    this->dataQueue.clear();
}

void Client::sendData(char* message) {
    sendData(message, APP_SEND);
}

/*
 * Send messge API
 */
void Client::sendMessage(char *value, int len, int destinationPort,
        int destinationAddress) {
    // intialisation
    Data *data = new Data;
    data->setKind(DATA);
    data->setByteLength(len);

    // meta-data
    data->setTime(simTime().dbl());

    // control-data
    data->setDestinationPort(destinationPort);
    data->setDestinationIPAddress(destinationAddress);

    // data
    data->setValue(value);

    sendMessageToLower(data);
}

}
;
// namespaces
