//
//  created on : Mar 5, 2014
//      author : Mr.Quan LE
//      email  : lequana2@gmail.com
//
//  functioning: TRA layer message
//

cplusplus {{
#include <ipAddress.h>
}};

class noncobject IpAddress;

namespace wsn_energy;

// Segment
packet UdpPacketInterface{
    int headerLength; // meta-data: header length, depends on specific format
}

packet UdpPacketStandard extends UdpPacketInterface{
// 	standard (non-compress) = 8 octets

	headerLength = 8;  // meta-data: header length, carried in-line

	short sourcePort;      // 2 octets of source port
	IpAddress destinationPortV6; // 	2 octets of destination port
	short length;          // 	2 octets of packet length
	short checksum;        // 	2 octets of check sum of pseudo-header (IP header) 
	
	int destinationPort; // meta
}

packet UdpPacketCompressed extends UdpPacketInterface{
// 	compressed HC1 = 3 octets RFC 4944
	headerLength = 4; // meta-data: header length (3) + data in-line (1)

//	The UDP header's checksum field is not compressed and is therefore carried in full.
//
//                      1                   2                   3
//      0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
//      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//      |HC_UDP encoding|     Fields carried in-line follow...
//      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//         Figure 16: HC_UDP (UDP common compressed header encoding)
//
//	UDP source port (bit 0):
//        0: Not compressed, carried "in-line" (Section 10.3.2)
//        1: Compressed to 4 bits.  The actual 16-bit source port is
//           obtained by calculating: P + short_port value.  The value of
//           P is the number 61616 (0xF0B0).  The short_port is expressed
//           as a 4-bit value which is carried "in-line" (Section 10.3.2)
//
//  UDP destination port (bit 1):
//        0: Not compressed, carried "in-line" (Section 10.3.2)
//        1: Compressed to 4 bits.  The actual 16-bit destination port is
//           obtained by calculating: P + short_port value.  The value of
//           P is the number 61616 (0xF0B0).  The short_port is expressed
//           as a 4-bit value which is carried "in-line" (Section 10.3.2)
//
//  Length (bit 2):
//        0: not compressed, carried "in-line" (Section 10.3.2)
//        1: compressed, length computed from IPv6 header length
//           information.  The value of the UDP length field is equal to
//           the Payload Length from the IPv6 header, minus the length of
//           any extension headers present between the IPv6 header and
//           the UDP header.
//
//  Reserved (bit 3 through 7)
	
	bool udpSourcePortCompressed;			// 1 bit 
	bool udpDestinationPortCompressed;		// 1 bit
	bool lengthCompressed;				    // 1 bit
	// 5 bit reserved
	
	// in-line fields
	short checksum; 			// 2 octets ALWAYS NON-COMPRESSED

	int inlineLength;				 // 0 bit compressed/ 16 bits non-compressed
	int inlineUdpSourcePort;      // 4 bit compressed/ 16 bits non-compressed 
	IpAddress inlineUdpDestinationPortV6; // 4 bit compressed/ 16 bits non-compressed
	
	int inlineUdpDestinationPort; // meta
}