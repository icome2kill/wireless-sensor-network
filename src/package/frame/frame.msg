//
//  created on : Mar 5, 2014
//      author : Mr.Quan LE
//      email  : lequana2@gmail.com
//
//  functioning: MAC layer message
//

cplusplus {{
#include <ipAddress.h>
#include <macAddress.h>
}};

class noncobject IpAddress;
class noncobject MacAddress;

namespace wsn_energy;

enum FRAME_TYPE{
    FRAME_BEACON  	= 0; // frame beacon
    FRAME_COMMAND 	= 1; // frame command
	FRAME_DATA 		= 2; // frame data
	FRAME_ACK  		= 3; // frame ack
}

// Frame
packet Frame{
    int numberTransmission = 0; // meta-data: number transmission
    int headerLength; 			// meta-data: determined upon frame creation
    
    // MAC protocol data unit (MPDU) = PHY service data unit (PSDU)
	
	// Frame Control Field 2 octets
	int 	frameType;        		    //  3 bit. Frame type field, see 802.15.4
  	int 	securityEnabled;  		    //  1 bit. True if security is used in this frame
  	int 	framePending;     			//  1 bit. True if sender has more data to send (in case of IP fragmentation)
  	bool 	ackRequired;      			//  1 bit. Is an ack frame required?
  	bool 	panIdCompression; 			//  1 bit. Is this a compressed header?
	int 	reserved; 		     	    //  3 bit. Unused bits
  	int 	destinationAddressMode;     //  2 bit. Destination address mode, see 802.15.4
  	int 	frameVersion;     		    //  2 bit. 802.15.4 frame version
  	int 	sourceAddressMode;          //  2 bit. Source address mode, see 802.15.4
  	
  	// Frame Check Sequence 2 octets FCS = MAC Footer MFR
  	uint16_t frameCheckSequence;
}

// Data frame
packet FrameDataStandard extends Frame{
// 	standard (non-compress) = 25 octets RFC 2460
   	headerLength = 25; // meta-data: length of this frame    
    
  	int dataSequenceNumber;	// 1 octet. Sequence number
  	
	uint16_t sourcePanID;	  				// 0/2   octets PANID - hard coded
	uint16_t destinationPanID; 				// 0/2   octets PANID - hard coded
	MacAddress sourceMacAddressEUI64; 		// 0/2/8 octets link-layer address address
	MacAddress destinationMacAddressEUI64;  // 0/2/8 octets link-layer addressaddress
	
	int sourceMacAddress; 		// meta
	int destinationMacAddress;  // meta
}

packet FrameDataCompressed extends Frame{
//	 compressed = 8 octets + normal header 25 octets
	 int headerLength = 32;
	
// 		order of header (sicslowmac)
//		5 octets: Mesh Addressing Header (short address)
//      2 octet:  Broadcast Header 
//      1 octet:  Fragmentation Header (not implemented yet)
// 		Header Compressed Header (dispatch)
//
// 		4 octets minimum Mesh header 4944
//
// 		0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
//      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//      |1 0|O|F|HopsLft| originator address, final address
//      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//	O: This 1-bit field SHALL be zero if the Originator Address is an
//      IEEE extended 64 bit address (EUI-64), or 1 if it is a short 16-
//      bit addresses.
//
//  F: This 1-bit field SHALL be zero if the Final Destination Address is
//      an IEEE extended 64 bit address (EUI-64), or 1 if it is a short
//      16-bit addresses.
//
//  Hops Left:  This 4-bit field SHALL be decremented by each forwarding
//      node before sending this packet towards its next hop.  The packet
//      is not forwarded any further if Hops Left is decremented to 0.
//      The value 0xF is reserved and signifies an 8-bit Deep Hops Left
//      field immediately following, and allows a source node to specify a
//      hop limit greater than 14 hops.
//
// 	Originator Address:  This is the link-layer address of the
//      Originator.
//
//  Final Destination Address:  This is the link-layer address of the
//      Final Destination.
//
//   Note that the 'O' and 'F' bits allow for a mix of 16 and 64-bit
//   addresses.  This is useful at least to allow for mesh layer
//   "broadcast", as 802.15.4 broadcast addresses are defined as 16-bit
//   short addresses.
//
//  2 octets Broadcast Header 
//                           1
//       0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
//      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//      |0|1|LOWPAN_BC0 |Sequence Number|
//      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//	1 octet dispatch (pattern - header)
//		  | 00  xxxxxx | NALP       - Not a LoWPAN frame               
//        | 01  000001 | IPv6       - uncompressed IPv6 Addresses      <-- ATTENTION
//        | 01  000010 | LOWPAN_HC1 - LOWPAN_HC1 compressed IPv6       <-- ATTENTION
//        |   ...      | reserved   - Reserved for future use          
//        | 01  010000 | LOWPAN_BC0 - LOWPAN_BC0 broadcast   <-- ATTENTION          
//        |   ...      | reserved   - Reserved for future use          
//        | 01  111111 | ESC        - Additional Dispatch octet follows 
	
	int  codeBit;						// 2 bits
	bool isOrignatorCompressed;			// 1 bit
	bool isFinalDestinationCompressed;	// 1 bit
	int hopLeft;						// 4 bits

	int hcDispatch;						// 1 octet
	
	int broadcastHeader;				// 1 octet
	int fragmentationHeader;			// 1 octet
	
	MacAddress orginatorAddressEUI64; 				// 2/8 octects
	MacAddress finalDestinationMacAddressEUI64;  	// 2/8 octects
	
	// normal MAC header
	int dataSequenceNumber;		// 1 octet. Sequence number
  	
	int sourcePanID;	  					// 0/2   octets PANID - hard-coded
	int destinationPanID; 					// 0/2   octets PANID - hard-coded
	MacAddress sourceMacAddressEUI64; 		// 0/2/8 octets link-layer address address
	MacAddress destinationMacAddressEUI64;  // 0/2/8 octets link-layer addressaddress
	
	int orginatorMacAddress; 			// meta
	int finalDestinationMacAddress;		// meta
	int sourceMacAddress; 		// meta
	int destinationMacAddress;  // meta
}

// ACK Frame
packet FrameACK extends Frame{
	headerLength = 5; // empty

   	int dataSequenceNumber;          	// 8 bit. Sequence number
}

// In case of synchronize, and neighbor discovery (unslotted CSMA/CA)
packet FrameBeacon extends Frame{
	headerLength = 26;
    
	int beaconSequenceNumber;	// 1 octet. Sequence number
	
	int sourcePanID;	  		// 0/2   octets PANID
	int destinationPanID; 		// 0/2   octets PANID
	int sourceMacAddress; 		// 0/2/8 octets link-layer address address
	int destinationMacAddress;  // 0/2/8 octets link-layer addressaddress
  	
  	// 2 octets Superframe specification
  	int beaconOrder;			// 4 bit
  	int superFrameOrder;		// 4 bit
  	int finalCAPslot;			// 4 bit
  	int batteryLifeExtension;	// 1 bit
  	int reserved;				// 1 bit
  	int PANcoordinator;			// 1 bit
  	int associationPermit;		// 1 bit

	// variable GTS
	// variable pendingAddressFields
	// variable beaconPayload
}

// In case of synchronize, and neighbor discovery (unslotted CSMA/CA)
packet FrameCommand extends Frame{
    headerLength = 25;
    
	int dataSequenceNumber;	// 8 bit. Sequence number
	
	int sourcePanID;	  		// 0/2   octets PANID
	int destinationPanID; 		// 0/2   octets PANID
	int sourceMacAddress; 		// 0/2/8 octets link-layer address address
	int destinationMacAddress;  // 0/2/8 octets link-layer addressaddress
  	
  	// 1 octets Command type
  	int commandType; // 8 bit

	//	Association request
	//	Association response
	//	Disassociation notification
	//	Data request
	//	PAN ID conflict notification
	//	Orphan Notification
	//	Beacon request
	//	Coordinator realignment
	//	GTS request

	// variable command payload
}
