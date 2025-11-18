///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
// Copyright (C) 2014 John Greb <hexameron@spam.no>                              //
// Copyright (C) 2015-2019 Edouard Griffiths, F4EXB <f4exb06@gmail.com>          //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef DEVICES_HACKRF_DEVICEHACKRFVALUES_H_
#define DEVICES_HACKRF_DEVICEHACKRFVALUES_H_

#include "export.h"

class DEVICES_API HackRFBandwidths {
public:
    static unsigned int getBandwidth(unsigned int bandwidth_index);
    static unsigned int getBandwidthIndex(unsigned int bandwidth);
    static const unsigned int m_nb_bw;
    static const unsigned int m_bw_k[];
};

class DEVICES_API HackRFValues {
public:
	HackRFValues();
	virtual ~HackRFValues();

	void queryDevice(struct hackrf_device* device);

	// TODO support separate rx/tx filter bandwidths
	// TODO drop static once I figure out to access this from hackrfinputgui.cpp
    static unsigned int getRxBandwidth(unsigned int bandwidth_index);
    static unsigned int getRxBandwidthCount() {
		return m_nb_bw_rx;
	}
    static unsigned int getRxBandwidthIndex(unsigned int bandwidth);

    static unsigned int getTxBandwidth(unsigned int bandwidth_index);
    static unsigned int getTxBandwidthCount() {
		return m_nb_bw_tx;
	}
    static unsigned int getTxBandwidthIndex(unsigned int bandwidth);

private:
	static unsigned int m_nb_bw_rx;
	static unsigned int m_bw_k_rx[32];
	static unsigned int m_nb_bw_tx;
	static unsigned int m_bw_k_tx[32];
};

#endif /* DEVICES_HACKRF_DEVICEHACKRFVALUES_H_ */
