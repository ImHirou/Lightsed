#ifndef LIGHTSED_OBJECT_H
#define LIGHTSED_OBJECT_H

#include "BaseObject.h"
#include "Locked.h"
#include "Light.h"

class Object : public BaseObject {
public:
    Object(ObjectType type=ObjectType::EMPTY) : BaseObject(type) {}

    operator Locked();
    operator Light();

};

#endif //LIGHTSED_OBJECT_H
