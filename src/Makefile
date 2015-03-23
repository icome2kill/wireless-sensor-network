#
# OMNeT++/OMNEST Makefile for wsn-energy
#
# This file was generated with the command:
#  opp_makemake -f --deep
#

# Name of target to be created (-o option)
TARGET = wsn-energy$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -Iapps \
    -Iapps/client \
    -Iapps/server \
    -Icore \
    -Icore/bytecount \
    -Icore/energest \
    -Icore/framer802154 \
    -Icore/mac \
    -Icore/mac/csma \
    -Icore/mac/nullmac \
    -Icore/net \
    -Icore/net/ipv6 \
    -Icore/net/rpl \
    -Icore/radio \
    -Icore/radio/cc2420 \
    -Icore/radio/nullradio \
    -Icore/rdc \
    -Icore/rdc/contikiMac \
    -Icore/rdc/nullrdc \
    -Icore/transport \
    -Icore/transport/udp \
    -Imote \
    -Ipackage \
    -Ipackage/data \
    -Ipackage/frame \
    -Ipackage/packet \
    -Ipackage/segment \
    -Ipackage/signal \
    -Ipackage/strobe \
    -Iutil \
    -Iutil/signal \
    -Iutil/statistic \
    -Iutil/world

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/apps/client/client.o \
    $O/apps/server/server.o \
    $O/core/myModule.o \
    $O/core/bytecount/count.o \
    $O/core/energest/energest.o \
    $O/core/framer802154/framer.o \
    $O/core/mac/mac.o \
    $O/core/mac/macAddress.o \
    $O/core/mac/csma/csma.o \
    $O/core/mac/nullmac/nullMAC.o \
    $O/core/net/ipAddress.o \
    $O/core/net/ipv6/ipv6.o \
    $O/core/net/rpl/rpl.o \
    $O/core/radio/radio.o \
    $O/core/radio/cc2420/cc2420.o \
    $O/core/radio/nullradio/nullRadio.o \
    $O/core/rdc/rdc.o \
    $O/core/rdc/contikiMac/contikiMAC.o \
    $O/core/rdc/nullrdc/nullRDC.o \
    $O/core/transport/udp/udp.o \
    $O/util/signal/mySignal.o \
    $O/util/statistic/statistic.o \
    $O/util/world/world.o \
    $O/package/data/data_m.o \
    $O/package/frame/frame_m.o \
    $O/package/packet/packet_m.o \
    $O/package/segment/segment_m.o \
    $O/package/signal/signal_m.o \
    $O/package/strobe/strobe_m.o

# Message files
MSGFILES = \
    package/data/data.msg \
    package/frame/frame.msg \
    package/packet/packet.msg \
    package/segment/segment.msg \
    package/signal/signal.msg \
    package/strobe/strobe.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f wsn-energy wsn-energy.exe libwsn-energy.so libwsn-energy.a libwsn-energy.dll libwsn-energy.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f apps/*_m.cc apps/*_m.h
	$(Q)-rm -f apps/client/*_m.cc apps/client/*_m.h
	$(Q)-rm -f apps/server/*_m.cc apps/server/*_m.h
	$(Q)-rm -f core/*_m.cc core/*_m.h
	$(Q)-rm -f core/bytecount/*_m.cc core/bytecount/*_m.h
	$(Q)-rm -f core/energest/*_m.cc core/energest/*_m.h
	$(Q)-rm -f core/framer802154/*_m.cc core/framer802154/*_m.h
	$(Q)-rm -f core/mac/*_m.cc core/mac/*_m.h
	$(Q)-rm -f core/mac/csma/*_m.cc core/mac/csma/*_m.h
	$(Q)-rm -f core/mac/nullmac/*_m.cc core/mac/nullmac/*_m.h
	$(Q)-rm -f core/net/*_m.cc core/net/*_m.h
	$(Q)-rm -f core/net/ipv6/*_m.cc core/net/ipv6/*_m.h
	$(Q)-rm -f core/net/rpl/*_m.cc core/net/rpl/*_m.h
	$(Q)-rm -f core/radio/*_m.cc core/radio/*_m.h
	$(Q)-rm -f core/radio/cc2420/*_m.cc core/radio/cc2420/*_m.h
	$(Q)-rm -f core/radio/nullradio/*_m.cc core/radio/nullradio/*_m.h
	$(Q)-rm -f core/rdc/*_m.cc core/rdc/*_m.h
	$(Q)-rm -f core/rdc/contikiMac/*_m.cc core/rdc/contikiMac/*_m.h
	$(Q)-rm -f core/rdc/nullrdc/*_m.cc core/rdc/nullrdc/*_m.h
	$(Q)-rm -f core/transport/*_m.cc core/transport/*_m.h
	$(Q)-rm -f core/transport/udp/*_m.cc core/transport/udp/*_m.h
	$(Q)-rm -f mote/*_m.cc mote/*_m.h
	$(Q)-rm -f package/*_m.cc package/*_m.h
	$(Q)-rm -f package/data/*_m.cc package/data/*_m.h
	$(Q)-rm -f package/frame/*_m.cc package/frame/*_m.h
	$(Q)-rm -f package/packet/*_m.cc package/packet/*_m.h
	$(Q)-rm -f package/segment/*_m.cc package/segment/*_m.h
	$(Q)-rm -f package/signal/*_m.cc package/signal/*_m.h
	$(Q)-rm -f package/strobe/*_m.cc package/strobe/*_m.h
	$(Q)-rm -f util/*_m.cc util/*_m.h
	$(Q)-rm -f util/signal/*_m.cc util/signal/*_m.h
	$(Q)-rm -f util/statistic/*_m.cc util/statistic/*_m.h
	$(Q)-rm -f util/world/*_m.cc util/world/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc apps/*.cc apps/client/*.cc apps/server/*.cc core/*.cc core/bytecount/*.cc core/energest/*.cc core/framer802154/*.cc core/mac/*.cc core/mac/csma/*.cc core/mac/nullmac/*.cc core/net/*.cc core/net/ipv6/*.cc core/net/rpl/*.cc core/radio/*.cc core/radio/cc2420/*.cc core/radio/nullradio/*.cc core/rdc/*.cc core/rdc/contikiMac/*.cc core/rdc/nullrdc/*.cc core/transport/*.cc core/transport/udp/*.cc mote/*.cc package/*.cc package/data/*.cc package/frame/*.cc package/packet/*.cc package/segment/*.cc package/signal/*.cc package/strobe/*.cc util/*.cc util/signal/*.cc util/statistic/*.cc util/world/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/apps/client/client.o: apps/client/client.cc \
	apps/client/client.h \
	core/framer802154/framer.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/radio/radio.h \
	package/data/data_m.h \
	package/frame/frame_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h \
	util/statistic/statistic.h
$O/apps/server/server.o: apps/server/server.cc \
	apps/server/server.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	package/data/data_m.h \
	package/packet/packet_m.h \
	package/strobe/strobe_m.h \
	util/statistic/statistic.h
$O/core/myModule.o: core/myModule.cc \
	core/framer802154/framer.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/radio/radio.h \
	package/frame/frame_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h
$O/core/bytecount/count.o: core/bytecount/count.cc \
	core/bytecount/count.h \
	core/framer802154/framer.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/radio/radio.h \
	package/frame/frame_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h \
	util/statistic/statistic.h
$O/core/energest/energest.o: core/energest/energest.cc \
	core/energest/energest.h \
	core/framer802154/framer.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/net/ipv6/ipv6.h \
	core/net/rpl/rpl.h \
	core/radio/radio.h \
	package/data/data_m.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/segment/segment_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h \
	util/statistic/statistic.h
$O/core/framer802154/framer.o: core/framer802154/framer.cc \
	core/framer802154/framer.h \
	core/mac/macAddress.h \
	core/net/ipAddress.h \
	package/frame/frame_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h
$O/core/mac/mac.o: core/mac/mac.cc \
	core/mac/mac.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/net/ipv6/ipv6.h \
	core/net/rpl/rpl.h \
	package/data/data_m.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/segment/segment_m.h \
	package/strobe/strobe_m.h \
	util/statistic/statistic.h
$O/core/mac/macAddress.o: core/mac/macAddress.cc \
	core/mac/macAddress.h
$O/core/mac/csma/csma.o: core/mac/csma/csma.cc \
	core/mac/csma/csma.h \
	core/mac/mac.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/strobe/strobe_m.h
$O/core/mac/nullmac/nullMAC.o: core/mac/nullmac/nullMAC.cc \
	core/mac/mac.h \
	core/mac/macAddress.h \
	core/mac/nullmac/nullMAC.h \
	core/myModule.h \
	core/net/ipAddress.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/strobe/strobe_m.h
$O/core/net/ipAddress.o: core/net/ipAddress.cc \
	core/mac/macAddress.h \
	core/net/ipAddress.h
$O/core/net/ipv6/ipv6.o: core/net/ipv6/ipv6.cc \
	core/bytecount/count.h \
	core/energest/energest.h \
	core/framer802154/framer.h \
	core/mac/mac.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/net/ipv6/ipv6.h \
	core/net/rpl/rpl.h \
	core/radio/radio.h \
	package/data/data_m.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/segment/segment_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h \
	util/signal/mySignal.h \
	util/statistic/statistic.h \
	util/world/world.h
$O/core/net/rpl/rpl.o: core/net/rpl/rpl.cc \
	core/energest/energest.h \
	core/mac/mac.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/net/ipv6/ipv6.h \
	core/net/rpl/rpl.h \
	package/data/data_m.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/segment/segment_m.h \
	package/strobe/strobe_m.h \
	util/statistic/statistic.h
$O/core/radio/radio.o: core/radio/radio.cc \
	core/energest/energest.h \
	core/framer802154/framer.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/net/ipv6/ipv6.h \
	core/net/rpl/rpl.h \
	core/radio/radio.h \
	package/data/data_m.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/segment/segment_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h \
	util/signal/mySignal.h \
	util/statistic/statistic.h \
	util/world/world.h
$O/core/radio/cc2420/cc2420.o: core/radio/cc2420/cc2420.cc \
	core/energest/energest.h \
	core/framer802154/framer.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/radio/cc2420/cc2420.h \
	core/radio/radio.h \
	package/frame/frame_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h \
	util/signal/mySignal.h \
	util/statistic/statistic.h \
	util/world/world.h
$O/core/radio/nullradio/nullRadio.o: core/radio/nullradio/nullRadio.cc \
	core/energest/energest.h \
	core/framer802154/framer.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/radio/nullradio/nullRadio.h \
	core/radio/radio.h \
	package/frame/frame_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h \
	util/signal/mySignal.h \
	util/statistic/statistic.h \
	util/world/world.h
$O/core/rdc/rdc.o: core/rdc/rdc.cc \
	core/bytecount/count.h \
	core/framer802154/framer.h \
	core/mac/mac.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/radio/radio.h \
	core/rdc/rdc.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h
$O/core/rdc/contikiMac/contikiMAC.o: core/rdc/contikiMac/contikiMAC.cc \
	core/framer802154/framer.h \
	core/mac/mac.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/radio/radio.h \
	core/rdc/contikiMac/contikiMAC.h \
	core/rdc/rdc.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h
$O/core/rdc/nullrdc/nullRDC.o: core/rdc/nullrdc/nullRDC.cc \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/rdc/nullrdc/nullRDC.h \
	core/rdc/rdc.h \
	package/frame/frame_m.h \
	package/packet/packet_m.h \
	package/strobe/strobe_m.h
$O/core/transport/udp/udp.o: core/transport/udp/udp.cc \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/transport/udp/udp.h \
	package/data/data_m.h \
	package/segment/segment_m.h \
	package/strobe/strobe_m.h \
	util/statistic/statistic.h
$O/package/data/data_m.o: package/data/data_m.cc \
	core/mac/macAddress.h \
	core/net/ipAddress.h \
	package/data/data_m.h
$O/package/frame/frame_m.o: package/frame/frame_m.cc \
	core/mac/macAddress.h \
	core/net/ipAddress.h \
	package/frame/frame_m.h
$O/package/packet/packet_m.o: package/packet/packet_m.cc \
	core/mac/macAddress.h \
	core/net/ipAddress.h \
	package/packet/packet_m.h
$O/package/segment/segment_m.o: package/segment/segment_m.cc \
	core/mac/macAddress.h \
	core/net/ipAddress.h \
	package/segment/segment_m.h
$O/package/signal/signal_m.o: package/signal/signal_m.cc \
	package/signal/signal_m.h
$O/package/strobe/strobe_m.o: package/strobe/strobe_m.cc \
	package/strobe/strobe_m.h
$O/util/signal/mySignal.o: util/signal/mySignal.cc \
	util/signal/mySignal.h
$O/util/statistic/statistic.o: util/statistic/statistic.cc \
	core/bytecount/count.h \
	core/energest/energest.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/net/ipv6/ipv6.h \
	core/net/rpl/rpl.h \
	package/data/data_m.h \
	package/packet/packet_m.h \
	package/segment/segment_m.h \
	package/strobe/strobe_m.h \
	util/statistic/statistic.h
$O/util/world/world.o: util/world/world.cc \
	core/framer802154/framer.h \
	core/mac/macAddress.h \
	core/myModule.h \
	core/net/ipAddress.h \
	core/radio/radio.h \
	package/frame/frame_m.h \
	package/signal/signal_m.h \
	package/strobe/strobe_m.h \
	util/signal/mySignal.h \
	util/statistic/statistic.h \
	util/world/world.h

