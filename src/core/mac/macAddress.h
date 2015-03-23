/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *  
 *  Functioning: MAC address utility
 */

#ifndef MACADDRESS_H_
#define MACADDRESS_H_

namespace wsn_energy {

class MacAddress
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

    MacAddress();
    MacAddress(int id);

    void print();
    bool isMatch(MacAddress*);
};

} /* namespace wsn_energy */

#endif /* MACADDRESS_H_ */
