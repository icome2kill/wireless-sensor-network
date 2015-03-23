//
//  created on : Mar 5, 2014
//      author : Mr.Quan LE
//      email  : lequana2@gmail.com
//
//  functioning: NET layer message
//

cplusplus {{
#include <ipAddress.h>
}};

class noncobject IpAddress;

namespace wsn_energy;

// ip packet type
enum IP_PACKET_NEXT_HEADER{
    NEXT_HEADER_UDP		= 0; // UDP  packet follows
    NEXT_HEADER_TCP		= 1; // TCP  packet follows
    NEXT_HEADER_ICMP	= 2; // ICMP packet follows
};

// icmp packet type
enum ICMP_TYPE{
    ICMP_RPL		= 155; // ICMP RPL, 0x9b confirmed by IANA (1 octet)
}

// rpl icmp packet type
enum ICMP_CODE{
	RPL_DIO_CODE   	  = 0;	// RPL DIO message, 0x00 confirmed by IANA (1 octet)
	RPL_DIS_CODE	  = 1;	// RPL DIS message, 0x01 confirmed by IANA (1 octet)
}

// Packet
packet IpPacketInterface{
    double time;  			// meta-data: timestamp
    int 	headerLength; 	// meta-data: header length, depends on specific format
}

packet IpPacketStandard extends IpPacketInterface{  
// 		standard (non-compress) = 40 octets RFC 2460
    headerLength = 40;
    
//     4 bits version
//     8 bits traffic class
//     20 bits flow label
//     2 octets payload length
//     1 octets next header
//     1 octets hop limit
//     16 octets IPv6 source
//     16 octets IPv6 destination
    
    int version;
    int trafficClass;
    int flowLabel;
    int payloadLength;
    int nextHeader; // type: ICMP, UDP, TCP
    int hopLimit;
    IpAddress sourceIpAddressV6;
    IpAddress destinationIpAddressV6;
    
    int sourceIpAddress;
    int destinationIpAddress;
}

packet IpPacketCompressed extends IpPacketInterface{
//	This common IPv6 header (as mentioned above) can
//	be compressed to 2 octets (1 octet for the HC1 encoding and 1 octet
//	for the Hop Limit), instead of 40 octets
//    
//    payload length included in 802.15.4 header
//    IPv6 source deprived from 802.15.4 header (link-layer address), reduce 16 octets 
//    IPv6 destination deprived from 802.15.4 header (link-layer address), reduce 16 octets 

//  	compressed HC1 = 2 octets RFC 4944
	
	headerLength = 2;

//	The "HC1 encoding" is shown below (starting with bit 0 and ending at
//  bit 7):
//
//		PI = prefix carried in-line non-compressed		
//		PC = prefix compressed
//		II = interface identifier in-line
//		IC = interface identifier compressed
//		
//  IPv6 source address (bits 0 and 1):
//  	00:  PI, II
//  	01:  PI, IC
//  	10:  PC, II
//  	11:  PC, IC
//
//  IPv6 destination address (bits 2 and 3):
//  	00:  PI, II
//  	01:  PI, IC
//  	10:  PC, II
//  	11:  PC, IC
//
//  Traffic Class and Flow Label (bit 4):
//  	0: not compressed, full 8 bits for Traffic Class and 20 bits
//     		for Flow Label are sent
//		1: Traffic Class and Flow Label are zero
//
//  Next Header (bits 5 and 6):
//  	00:  not compressed, full 8 bits are sent
//  	01:  UDP
//  	10:  ICMP
//  	11:  TCP
//
//  HC2 encoding(bit 7):
//  	0: No more header compression bits
//  	1: HC1 encoding immediately followed by more header compression
//     		bits per HC2 encoding format.  Bits 5 and 6 determine which
//     		of the possible HC2 encodings apply (e.g., UDP, ICMP or TCP
//     		encodings).

	int sourceIpAddress; 			// 2 bits + 0 bit compressed/ 128 bits non-compressed
	int destinationIpAddress; 		// 2 bits + 0 bit compressed/ 128 bits non-compressed
	int trafficClassAndFlowLabel; 	// 1 bit + 0 bit compressed/  28 bits non-compressed
	int nextHeader;					// 2 bits + 0 bit compressed/ 8 bits non-compressed
	int hc2encoding;				// 1 bit (determines whether any header compression bits)
	
	int hopLimit; 					// 1 octet NEVER COMPRESSED
	
	int metaHopLimit;			  // in-line: hop limit
	IpAddress metaSourceIpAddressV6;	    // meta-data: source Ip address
	IpAddress metaDestinationIpAddressV6; // meta-data: destination ip address
	
	int metaSourceIpAddress;	    // meta
	int  metaDestinationIpAddress; // meta
}

// ICMP Packet
packet IcmpPacket{
	// standard (non-compress) = 8 octets
	int headerLength = 8;
	
	// 1 octets of type
	// 1 octets of code
	// 2 octets of checksum
	// 2 octets of other message specific information
	
	int type; // RPL ICMPv6
	int code; // DIO, DIS
	int checksum; 
	int others;
}

packet DIO{
    int senderID; // meta-data: sender IP
	int payloadLength = 24; // meta-data: length of DIO 
    
	int instanceID;
	int version; // version
	unsigned long rank; // rank 
	bool grounded;
	bool o;
	int modeOfOperation;
	int preference;
	int dstn;
	int flags;
	int reserved;
	int dodagID; // DODAGID
}

packet DIS{
	int payloadLength = 2; // meta-data: length of DIO
	
	// 1 octet flag
	// 1 octet reserved
	
	int flag;
	int reserved;
}