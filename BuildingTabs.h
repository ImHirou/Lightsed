#ifndef LIGHTSED_BUILDINGTABS_H
#define LIGHTSED_BUILDINGTABS_H

#include "Tab.h"

namespace BuildTabs {
    Tab emptyTab(0,0,0,0,"");
    Tab building1Tab(215, 220, 615, 620, "Upgrades", BaseObject::BUILDING1);
    Tab chanceTab(215, 220, 615, 620, "Chance", BaseObject::CHANCE_BUILDING);
    Tab automationTab(215, 220, 615, 620, "Automation", BaseObject::AUTOMATION_BUILDING);
}

#endif //LIGHTSED_BUILDINGTABS_H
