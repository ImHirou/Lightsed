#include "Building.h"
#include "BuildingTabs.h"

Tab& Building::tabByType(BaseObject::ObjectType type) const {
    switch (type) {
        case BaseObject::BUILDING1:             return BuildTabs::building1Tab;
        case BaseObject::CHANCE_BUILDING:       return BuildTabs::chanceTab;
        case BaseObject::AUTOMATION_BUILDING:   return BuildTabs::automationTab;
        default: return BuildTabs::emptyTab;
    }
}

Tab& Building::getTab() { return m_tab; }