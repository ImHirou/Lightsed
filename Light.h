#ifndef LIGHTSED_LIGHT_H
#define LIGHTSED_LIGHT_H

#include "BaseObject.h"

class Object;

class Light : public BaseObject {
protected:
    long long m_light;
public:
    explicit Light(long long light=1) : BaseObject(ObjectType::LIGHT), m_light(light) {}

    void setLight(long long light);
    long long getLight() const;

};

#endif //LIGHTSED_LIGHT_H
