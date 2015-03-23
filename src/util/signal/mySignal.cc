/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to mySignal.h
 */

#include "mySignal.h"

namespace wsn_energy {

mySignal::mySignal()
{
  this->isCorrupted = false;
}

mySignal::mySignal(int radioSenderID, int radioRecverID)
{
  mySignal();
  this->radioSenderID = radioSenderID;
  this->radioRecverID = radioRecverID;
}

void mySignal::corrupt()
{
  this->isCorrupted = true;
}

bool mySignal::getIsCorrupted()
{
  return this->isCorrupted;
}

} /* namespace wsn_energy */
