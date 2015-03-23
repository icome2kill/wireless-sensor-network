/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: Managing signal between 2 motes
 */

#ifndef SIGNAL_H_
#define SIGNAL_H_

namespace wsn_energy {

class mySignal
{
  private:
    bool isCorrupted;

    int rssi;        // 8 bit RSSI offset

  public:
    int radioSenderID;
    int radioRecverID;

    mySignal();
    mySignal(int radioSenderID, int radioRecverID);

    void corrupt();

    bool getIsCorrupted();
};

} /* namespace wsn_energy */

#endif /* SIGNAL_H_ */
