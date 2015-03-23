/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  Functioning: IPv6 address utility
 */

#ifndef IPADDRESS_H_
#define IPADDRESS_H_

#include <macAddress.h>

namespace wsn_energy {

class IpAddress
{
  public:
    bool isOK;
    int octet1;
    int octet2;
    int octet3;
    int octet4;
    int octet5;
    int octet6;
    int octet7;
    int octet8;
    int octet9;
    int octet10;
    int octet11;
    int octet12;
    int octet13;
    int octet14;
    int octet15;
    int octet16;

    IpAddress();
    IpAddress(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
    IpAddress(MacAddress*);

    void print();
    bool isMatch(IpAddress*);
};

} /* namespace wsn_energy */

#endif /* IPADDRESS_H_ */
