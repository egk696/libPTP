// ============================================================================
//
// Copyright 2013-2015 Wolfgang Wallner (wolfgang-wallner AT gmx.at)
//
// This file is part of the LibPTP project.
//
// The LibPTP project is free software: you can redistribute it
// and/or modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation, either version 3 of the License,
// or (at your option) any later version.
//
// The LibPTP project is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License.com for more details.
//
// You should have received a copy of the GNU General Public License.com
// along with The LibPTP project.
// If not, see <http://www.gnu.org/licenses/>.
//
// ============================================================================

#ifndef LIBPTP_PTP_ETHER_ENCAP_H_
#define LIBPTP_PTP_ETHER_ENCAP_H_

// ======================================================
// Includes
// ======================================================

#include "EtherEncap.h"
#include "MACAddress.h"

#include "IInitBase.h"

// ======================================================
// Types
// ======================================================

// ======================================================
// Declarations
// ======================================================

class PTP_EtherEncap : public EtherEncap, public IInitBase
{
    private:

        // Configuration
        bool                PTP_Enable;
        const   MACAddress  PtpMcMAC;
        const   MACAddress  PtpMcPDelayMAC;

        // Inherited EtherEncap API
        void processPacketFromHigherLayer(cPacket *msg);
        void processFrameFromMAC(EtherFrame *frame);

    protected:

        // Init API
        void    ParseParameters();

        // OMNeT API
        int     numInitStages() const;
        void    initialize(int stage);

    public:
        PTP_EtherEncap();
};

#endif

