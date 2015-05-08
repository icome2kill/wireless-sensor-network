/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to csma.h
 */

#include "csma.h"
#include "packet_m.h"

#define BACKOFF_PERIOD                0.0032 // second, 20 symbols
#define MAC_MIN_BE                    3 // min backoff exponent
#define MAC_MAX_BE                    5 // max backoff exponent
#define MAX_BACKOFF_TRANSMISSION      3 // 3 tries per frame

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

Define_Module(csma);

void csma::deferPacket()
{
  /* dismiss + announce failure duty */
  if (bufferMAC->getNumberTransmission() > MAX_BACKOFF_TRANSMISSION)
  {
    // consider IFS
    if (this->bufferMAC->getByteLength() > MAX_SIFS_FRAME_SIZE)
      selfTimer(LIFS, MAC_EXPIRE_IFS);
    else
      selfTimer(SIFS, MAC_EXPIRE_IFS);

//    sendResult(MAC_RELIABLE);

    endMACphase();
  }
  /* unslotted csma */
  else
  {
    double backoff;
    int backoff_transmission, backoff_exponent;

    backoff_exponent =
    MAC_MAX_BE < bufferMAC->getNumberTransmission() + MAC_MIN_BE ? MAC_MAX_BE :
        bufferMAC->getNumberTransmission() + MAC_MIN_BE; // truncate

    backoff_transmission = 1 << backoff_exponent;

    int backoffUnit;

    if (getModuleByPath("^.^")->par("rand").doubleValue() == 0)
      backoffUnit = (rand() % (backoff_transmission));
    else if (getModuleByPath("^.^")->par("rand").doubleValue() == 1)
      backoffUnit = (intuniform(0, backoff_transmission));

    // create unsynchronization
    backoff = backoffUnit * BACKOFF_PERIOD + intuniform(0, 1000) / 1000000000.0;

    if (DEBUG)
      std::cout << "Random " << backoff_transmission << "/" << backoffUnit << "/" << backoff << endl;

    bufferMAC->setNumberTransmission(bufferMAC->getNumberTransmission() + 1);

    /* request to perform CCA */
    selfTimer(backoff, MAC_CCA_REQUEST);
  }
}

} /* namespace wsn_energy */
