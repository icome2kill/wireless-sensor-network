/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  Functioning: refers to ipAddress.h
 */

#include <ipAddress.h>
#include <iostream>

namespace wsn_energy {

IpAddress::IpAddress()
{
}

IpAddress::IpAddress(int octet1, int octet2, int octet3, int octet4, int octet5, int octet6, int octet7, int octet8,
    int octet9, int octet10, int octet11, int octet12, int octet13, int octet14, int octet15, int octet16)
{
  this->octet1 = octet1;
  this->octet2 = octet2;
  this->octet3 = octet3;
  this->octet4 = octet4;
  this->octet5 = octet5;
  this->octet6 = octet6;
  this->octet7 = octet7;
  this->octet8 = octet8;
  this->octet9 = octet9;
  this->octet10 = octet10;
  this->octet11 = octet11;
  this->octet12 = octet12;
  this->octet13 = octet13;
  this->octet14 = octet14;
  this->octet15 = octet15;
  this->octet16 = octet16;
}

IpAddress::IpAddress(MacAddress* macAddress)
{
  // fe80::/64 link-local prefix
  this->octet1 = 0xfe;
  this->octet2 = 0x80;
  this->octet3 = 0;
  this->octet4 = 0;
  this->octet5 = 0;
  this->octet6 = 0;
  this->octet7 = 0;
  this->octet8 = 0;

  // last 32 bit
  this->octet9 = macAddress->octet1;
  this->octet10 = macAddress->octet2;
  this->octet11 = macAddress->octet5;
  this->octet12 = macAddress->octet4;
  this->octet13 = macAddress->octet5;
  this->octet14 = macAddress->octet6;
  this->octet15 = macAddress->octet7;
  this->octet16 = macAddress->octet8;
}

void IpAddress::print()
{
  std::cout << std::hex << this->octet1;
  std::cout << std::hex << this->octet2 << ":";
  std::cout << std::hex << this->octet3;
  std::cout << std::hex << this->octet4 << ":";
  std::cout << std::hex << this->octet5;
  std::cout << std::hex << this->octet6 << ":";
  std::cout << std::hex << this->octet7;
  std::cout << std::hex << this->octet8 << ":";
  std::cout << std::hex << this->octet9;
  std::cout << std::hex << this->octet10 << ":";
  std::cout << std::hex << this->octet11;
  std::cout << std::hex << this->octet12 << ":";
  std::cout << std::hex << this->octet13;
  std::cout << std::hex << this->octet14 << ":";
  std::cout << std::hex << this->octet15;
  std::cout << std::hex << this->octet16 << '\n';

}

bool IpAddress::isMatch(IpAddress* compare)
{
  if (this->octet1 != compare->octet1)
    return false;
  if (this->octet2 != compare->octet2)
    return false;
  if (this->octet3 != compare->octet3)
    return false;
  if (this->octet4 != compare->octet4)
    return false;
  if (this->octet5 != compare->octet5)
    return false;
  if (this->octet6 != compare->octet6)
    return false;
  if (this->octet7 != compare->octet7)
    return false;
  if (this->octet8 != compare->octet8)
    return false;
  if (this->octet9 != compare->octet9)
    return false;
  if (this->octet10 != compare->octet10)
    return false;
  if (this->octet11 != compare->octet11)
    return false;
  if (this->octet12 != compare->octet12)
    return false;
  if (this->octet13 != compare->octet13)
    return false;
  if (this->octet14 != compare->octet14)
    return false;
  if (this->octet15 != compare->octet15)
    return false;
  if (this->octet16 != compare->octet16)
    return false;

  return true;
}

} /* namespace wsn_energy */
