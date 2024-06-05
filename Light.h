#ifndef LIGHTSED_LIGHT_H
#define LIGHTSED_LIGHT_H

#include "BaseObject.h"

class Object;

class Light : public BaseObject {
public:
    Light() : BaseObject(ObjectType::LIGHT) {}

};

#endif //LIGHTSED_LIGHT_H
