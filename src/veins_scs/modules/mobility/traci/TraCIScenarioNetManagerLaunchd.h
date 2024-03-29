//
// Copyright (C) 2006-2012 Christoph Sommer <christoph.sommer@uibk.ac.at>
// Copyright (C) 2023 TOYOTA MOTOR CORPORATION. ALL RIGHTS RESERVED.
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// This program was developed based on Veins Framework (https://veins.car2x.org/). 
// The original code can be found at `veins/modules/mobility/traci/TraCIScnarioManagerLaunchd.d` of Veins-5.2.

#pragma once

#include "veins/veins.h"

#include "TraCIScenarioNetManager.h"

namespace veins {

/**
 * @brief
 * Extends the TraCIScenarioManager for use with sumo-launchd.py and SUMO.
 *
 * Connects to a running instance of the sumo-launchd.py script
 * to automatically launch/kill SUMO when the simulation starts/ends.
 *
 * All other functionality is provided by the TraCIScenarioManager.
 *
 * See the Veins website <a href="http://veins.car2x.org/"> for a tutorial, documentation, and publications </a>.
 *
 * @author Christoph Sommer, David Eckhoff
 *
 * @see TraCIMobility
 * @see TraCIScenarioManager
 *
 */
class VEINS_API TraCIScenarioNetManagerLaunchd : virtual public TraCIScenarioNetManager {
public:
    ~TraCIScenarioNetManagerLaunchd() override;
    void initialize(int stage) override;
    void finish() override;

protected:
    cXMLElement* launchConfig; /**< launch configuration to send to sumo-launchd */
    int seed; /**< seed value to set in launch configuration, if missing (-1: current run number) */

    void init_traci() override;
};

class VEINS_API TraCIScenarioNetManagerLaunchdAccess {
public:
    TraCIScenarioNetManagerLaunchd* get()
    {
        return FindModule<TraCIScenarioNetManagerLaunchd*>::findGlobalModule();
    };
};

} // namespace veins
