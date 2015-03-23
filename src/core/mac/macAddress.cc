/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *  
 *  Functioning: refer to macAddress.h
 */

#include <macAddress.h>
#include <iostream>

namespace wsn_energy {

MacAddress::MacAddress()
{
}

MacAddress::MacAddress(int id)
{
  this->octet1 = 0x0;
  this->octet2 = 0x12;
  this->octet3 = 0x74;
  this->octet4 = id;
  this->octet5 = 0x00;
  this->octet6 = id;
  this->octet7 = id;
  this->octet8 = id;
}

void MacAddress::print()
{
  std::cout << std::hex << this->octet1 << ":";
  std::cout << std::hex << this->octet2 << ":";
  std::cout << std::hex << this->octet3 << ":";
  std::cout << std::hex << this->octet4 << ":";
  std::cout << std::hex << this->octet5 << ":";
  std::cout << std::hex << this->octet6 << ":";
  std::cout << std::hex << this->octet7 << ":";
  std::cout << std::hex << this->octet8 << '\n';
}

bool MacAddress::isMatch(MacAddress* compare)
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

  return true;
}

} /* namespace wsn_energy */
