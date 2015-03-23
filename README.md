wsn-energy
==========

Abstract:

	This project provides a simple IoT communication
	stack framework with 6 layers: application,
	transport, network, mac, radio duty-cycling (RDC)
	and physics.

	It aslo implemented 6LoWPAN addressing, 
	and ContikiMAC in RDC layer.

    This file describes the build process for 
    preparing the project in OMNeT++ v4.4 and later.

Table of Contents:

    1) Requirements
    2) Running project
	3) Reading result

---

1) Requirements

- OMNeT++ v.4.4 and later

Please download the lastest OMNeT++ release at
http://www.omnetpp.org/omnetpp/cat_view/17-downloads/1-omnet-releases

Then following install guide at
http://omnetpp.org/doc/omnetpp/InstallGuide.pdf 

---

2) Running project

After installing in OMNeT++ the INET framework, follow
exactly the same process to import ccn-lite-omnet. Namely, 

 (Menu) File
   ->Import

    ->General
     ->Existing Projects in Workspace
     
       ->(radio) Select Source directory
        ->(tick) source
          ->Finish

Next proceed to re-index by right-clicking on the newly
imported project at the Project Explorer and selecting 

 Index -> Re-build

Finally, build the ccn-lite-omnet project

 (Menu) Project -> Build Project

That's it!

---

3) Simulation results

The network configuration set up is 
located at simulations/omnetpp.ini

After building and running project,
the result is extracted and exported
to file simulations/results/General.anf

It may took 5 minutes to create this 
file when running the first time.

---

4) Project hierrarchy

In the project you will find the following

	simulations/
		results/		folder contains simulation resource
		omnetpp.ini	file contains network configuration
		WSN.ned		file contains sensor nodes/base station info

	src/
		app				folder contains applications
		core			folder contain communication stack implementation
			trans		at transport layer
			net			at network layer
			mac			at mac layer
			rdc			at rdc layer
			radio		at phy layer
			energest	energy estimation module
			framer802154 frame creater library
		mote			sensor motes setup
		package			folder contains packet definition
			data		at application layer
			segment		at transport layer
			packet		at network layer	
			frame		at mac/rdc layer
			signal		at physics layer
			strobe		command within project
		util			contains utilities funtions
			signal		signal information
			statistics	statistics function
			world		manage devices' position, connection and transmission
# eof
