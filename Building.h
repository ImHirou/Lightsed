#ifndef LIGHTSED_BUILDING_H
#define LIGHTSED_BUILDING_H

#include "BaseObject.h"
#include "Tab.h"

class Building : public BaseObject {
private:
    Tab& m_tab;
public:
    Building(ObjectType type=EMPTY) : BaseObject(type), m_tab(tabByType(type)) { }

    Tab& tabByType(ObjectType type) const;
    Tab& getTab();

};


#endif //LIGHTSED_BUILDING_H
