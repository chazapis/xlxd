//
//  cdextraopenprotocol.h
//  xlxd
//
//  Created by Antony Chazapis (SV9OAN) on 19/12/2018.
//  Copyright © 2015 Jean-Luc Deltombe (LX3JL). All rights reserved.
//
// ----------------------------------------------------------------------------
//    This file is part of xlxd.
//
//    xlxd is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    xlxd is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Foobar.  If not, see <http://www.gnu.org/licenses/>. 
// ----------------------------------------------------------------------------

#ifndef cdextraopenprotocol_h
#define cdextraopenprotocol_h

#include "cdextraprotocol.h"

////////////////////////////////////////////////////////////////////////////////////////

// With the D-STAR vocoder extension by SV9OAN, voice in D-STAR streams can be encoded
// with either AMBE or Codec 2. The extension is backwards compatible and can be used
// with all current D-STAR hardware (repeaters, hotspots, etc.) and software
// (repeater controllers, reflectors, etc.), except - of course - transceivers.

// Although implementations of the vocoder extension can use the same reflector connections
// as AMBE-only clients, it should be avoided, to save the user confusion and establish
// interoperability.

// xlxd, can be used to transcode and bridge the two formats. This is done by
// implementing another DExtra listener on a different port (30201 instead of 30001).
// This port is to be used by reflectors using the "ORF" prefix (Open ReFlector).
// Any client connected to an ORF reflector will receive streams encoded with Codec 2.
// All other D-STAR protocol handlers will still send out data encoded with AMBE.
// Note that the protocol/port only affects data transmitted by the reflector.
// The stream vocoder is recognized in all protocol handlers, so a client can still
// transmit data using any vocoder on any port. The rationale behind this is that
// DExtra links may be used by repeaters or other reflectors, so it is not really
// possible to know what their clients support. So, nothing will change when linking
// a repeater to an XRF reflector, but will do when linking to an ORF one.


////////////////////////////////////////////////////////////////////////////////////////
// class

class CDextraOpenProtocol : public CDextraProtocol
{
public:
    // constructor
    CDextraOpenProtocol() {};
    
    // destructor
    virtual ~CDextraOpenProtocol() {};
    
    // identity
    int GetProtocol(void) const { return PROTOCOL_DEXTRA_OPEN; }
};

////////////////////////////////////////////////////////////////////////////////////////
#endif /* cdextraopenprotocol_h */
