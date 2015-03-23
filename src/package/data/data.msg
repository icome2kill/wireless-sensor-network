//
//  created on : Mar 5, 2014
//      author : Mr.Quan LE
//      email  : lequana2@gmail.com
//
//  functioning: APP layer message
//

cplusplus {{
#include <ipAddress.h>
}};

class noncobject IpAddress;

namespace wsn_energy;

// Data
packet Data{
    double time;  		// meta-data: timestamp upon sending
    
    int destinationPort; 	  // meta-data: destination port
    int destinationIPAddress; // meta-data: destination IP Address
    
    IpAddress destinationIPAddressV6;
    
	string value; 		// undefined length, data to be sent to server
}