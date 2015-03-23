//
//  created on : Mar 5, 2014
//      author : Mr.Quan LE
//      email  : lequana2@gmail.com
//
//  functioning: PHY layer message
//

namespace wsn_energy;

packet Raw{
    bool bitError;
    
    // 6 octets preamable
    int headerLength = 6;
    
    // fields
    // SHR synchronisation header
    // 4 octets (4 octets 0x00) preamable sequence
    // 1 octet  (1 octet  0xA7) start of frame delimeter (SFD)
    // PHR physical header
    // 1 octet frame length (does not count it self)
    
    // 127 octets maximum payload length
    // PHY protocol data unit (PPDU)
    int maxPayloadLength = 127;
}