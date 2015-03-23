//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <framer802154/framer.h>
#include <strobe_m.h>
#include <frame_m.h>

#ifndef DEBUG
#define DEBUG 0
#endif

namespace wsn_energy {

bool Framer::createFramer(Raw*& bufferTXFIFO, Frame* frame)
{
  bufferTXFIFO = new Raw;
  bufferTXFIFO->setKind(DATA);
  bufferTXFIFO->setByteLength(bufferTXFIFO->getHeaderLength());

  /* OK, now we have field lengths.  Time to actually construct */
  /* the outgoing frame, and store it in tx_frame_buffer */
  uint8_t *tx_frame_buffer;
  tx_frame_buffer = (uint8_t*) malloc(frame->getByteLength() * sizeof(uint8_t));

  // First octet
  tx_frame_buffer[0] = (frame->getFrameType() & 7) | ((frame->getSecurityEnabled() & 1) << 3)
      | ((frame->getFramePending() & 1) << 4) | ((frame->getAckRequired() & 1) << 5)
      | ((frame->getPanIdCompression() & 1) << 6);

  // Second octet
  tx_frame_buffer[1] = ((frame->getDestinationAddressMode() & 3) << 2) | ((frame->getFrameVersion() & 3) << 4)
      | ((frame->getSourceAddressMode() & 3) << 6);

  switch (frame->getFrameType())
  {
    case FRAME_DATA: {
      if (simulation.getModuleByPath("WSN")->par("usingHDC"))
      {
        // Compress using HC01

        /* sequence number */
        tx_frame_buffer[2] = (check_and_cast<FrameDataCompressed*>(frame))->getDataSequenceNumber();
        int pos = 3;

        /* Destination PAN ID */
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getDestinationPanID() & 0xff;
        tx_frame_buffer[pos++] = (check_and_cast<FrameDataCompressed*>(frame)->getDestinationPanID() >> 8) & 0xff;

        /* Destination address */
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getDestinationMacAddressEUI64().octet1;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getDestinationMacAddressEUI64().octet2;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getDestinationMacAddressEUI64().octet3;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getDestinationMacAddressEUI64().octet4;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getDestinationMacAddressEUI64().octet5;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getDestinationMacAddressEUI64().octet6;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getDestinationMacAddressEUI64().octet7;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getDestinationMacAddressEUI64().octet8;

        /* Source PAN ID */
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getSourcePanID() & 0xff;
        tx_frame_buffer[pos++] = (check_and_cast<FrameDataCompressed*>(frame)->getSourcePanID() >> 8) & 0xff;

        /* Source address */
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getSourceMacAddressEUI64().octet1;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getSourceMacAddressEUI64().octet2;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getSourceMacAddressEUI64().octet3;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getSourceMacAddressEUI64().octet4;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getSourceMacAddressEUI64().octet5;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getSourceMacAddressEUI64().octet6;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getSourceMacAddressEUI64().octet7;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataCompressed*>(frame)->getSourceMacAddressEUI64().octet8;
      }
      else
      {
        /* sequence number */
        tx_frame_buffer[2] = (check_and_cast<FrameDataStandard*>(frame))->getDataSequenceNumber();
        int pos = 3;

        /* Destination PAN ID */
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getDestinationPanID() & 0xff;
        tx_frame_buffer[pos++] = (check_and_cast<FrameDataStandard*>(frame)->getDestinationPanID() >> 8) & 0xff;

        /* Destination address */
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getDestinationMacAddressEUI64().octet1;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getDestinationMacAddressEUI64().octet2;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getDestinationMacAddressEUI64().octet3;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getDestinationMacAddressEUI64().octet4;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getDestinationMacAddressEUI64().octet5;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getDestinationMacAddressEUI64().octet6;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getDestinationMacAddressEUI64().octet7;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getDestinationMacAddressEUI64().octet8;

        /* Source PAN ID */
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getSourcePanID() & 0xff;
        tx_frame_buffer[pos++] = (check_and_cast<FrameDataStandard*>(frame)->getSourcePanID() >> 8) & 0xff;

        /* Source address */
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getSourceMacAddressEUI64().octet1;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getSourceMacAddressEUI64().octet2;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getSourceMacAddressEUI64().octet3;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getSourceMacAddressEUI64().octet4;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getSourceMacAddressEUI64().octet5;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getSourceMacAddressEUI64().octet6;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getSourceMacAddressEUI64().octet7;
        tx_frame_buffer[pos++] = check_and_cast<FrameDataStandard*>(frame)->getSourceMacAddressEUI64().octet8;
      }
      break;
    }

    case FRAME_ACK: {
      /* sequence number */
      tx_frame_buffer[2] = (check_and_cast<FrameACK*>(frame))->getDataSequenceNumber();
      break;
    }
  }

  free(tx_frame_buffer);
  bufferTXFIFO->encapsulate(frame);

  /* show packet length (bytes) */
  if (DEBUG)
    ev << "Radio length " << bufferTXFIFO->getByteLength() << endl;

  /* check packet length (127 + 6 bytes) */
  if (bufferTXFIFO->getByteLength() > bufferTXFIFO->getHeaderLength() + bufferTXFIFO->getMaxPayloadLength())
    return false; // does not success
  else
    return true; // success
}

} /* namespace wsn_energy */
