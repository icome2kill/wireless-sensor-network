/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to server.h
 */

#include "server.h"
#include "statistic.h"
#include "packet_m.h"
#include <iostream>
#include <fstream>

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

Define_Module(Server);

void Server::initialize() {
    this->macAddress = new MacAddress(this->getId());
    // set gloabl server address
    // network address aaaa::/64
    // suppose it is a MAC-48 from 64 bit by putting ff::fe to midle
    // server address aaaa::ff::fe:1
    this->ipAddress = new IpAddress(170, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255,
            254, 0, 0, 1);

    if (DEBUG) {
        std::cout << this->getFullPath() << "has mac address ";
        this->macAddress->print();
        std::cout << this->getFullPath() << "has tentative link-local address ";
        this->ipAddress->print();
        std::cout << endl;
    }

    // create new session myfile
    std::ofstream myfile;
    myfile.open("data.txt");
    myfile << "[Data received from client]";
    myfile.close();
}

void Server::processSelfMessage(cPacket* packet) {
}

void Server::processUpperLayerMessage(cPacket* packet) {
    // this is highest layer
    return;
}

std::vector<std::string> &split(const std::string &s, char delim,
        std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void Server::processLowerLayerMessage(cPacket* packet) {
    Data* data = check_and_cast<Data*>(packet);

    // Write value to myfile
    std::ofstream myfile;
    myfile.open("data.txt", std::ios::app);
    myfile << "\n" << data->getValue();
    myfile.close();

    char myfilename[100] = { 0 };

    if (DEBUG)
        this->getParentModule()->bubble(data->getValue());

    // End to end statistics
    if (simulation.getModuleByPath("WSN") != NULL) {
        ((Statistic*) simulation.getModuleByPath("statistic"))->registerStatistic(
        APP_RECV);
        ((Statistic*) simulation.getModuleByPath("statistic"))->registerStatisticDelay(
        DELAY_APP_LAYER, simTime().dbl() - data->getTime());

        std::vector<std::string> tokens = split(data->getValue(), '|');
        std::string id = tokens.at(0);
        for (unsigned int i = 1; i < tokens.size(); i++) {
            std::vector<std::string> tokens2 = split(tokens.at(i), '/');
            char value = tokens.at(i).at(0);
            if (value > '0' && value < '5') {
                int dataType = APP_RECV;
                int dataTypeDelay = DELAY_APP_LAYER;

                if (value == '1') {
                    // Temperature data
                    myfilename[0] = '\0';
                    sprintf(myfilename, "server_data/id_%s_data_light.txt",
                            id.c_str());
                    myfile.open(myfilename, std::ios::app);
                    dataType = APP_RECV_LIGHT;
                    dataTypeDelay = APP_RECV_LIGHT_DELAY;
                } else if (value == '2') {
                    myfilename[0] = '\0';
                    sprintf(myfilename,
                            "server_data/id_%s_data_temperature.txt",
                            id.c_str());
                    myfile.open(myfilename, std::ios::app);
                    dataType = APP_RECV_TEMPERATURE;
                    dataTypeDelay = APP_RECV_TEMPERATURE_DELAY;
                } else if (value == '3') {
                    myfilename[0] = '\0';
                    sprintf(myfilename, "server_data/id_%s_data_moisture.txt",
                            id.c_str());
                    myfile.open(myfilename, std::ios::app);
                    dataType = APP_RECV_MOISTURE;
                    dataTypeDelay = APP_RECV_MOISTURE_DELAY;
                } else if (value == '4') {
                    myfilename[0] = '\0';
                    sprintf(myfilename, "server_data/id_%s_data_soil.txt",
                            id.c_str());
                    myfile.open(myfilename, std::ios::app);
                    dataType = APP_RECV_SOIL;
                    dataTypeDelay = APP_RECV_SOIL_DELAY;
                }
                myfile << simTime().inUnit(SIMTIME_MS) << " " << tokens2.at(1)
                        << "\n";
                myfile.close();
                ((Statistic*) simulation.getModuleByPath("statistic"))->registerStatistic(
                        dataType);
                ((Statistic*) simulation.getModuleByPath("statistic"))->registerStatisticDelay(
                        dataTypeDelay, simTime().dbl() - data->getTime());
            }
        }
    }

    delete packet;
}

}
;
// namespace
