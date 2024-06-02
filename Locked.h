#ifndef LIGHTSED_LOCKED_H
#define LIGHTSED_LOCKED_H

#include "BaseObject.h"

class Object;

class Locked : public BaseObject {
private:
    long long m_cost;
public:
    Locked(ObjectType type=ObjectType::EMPTY) : BaseObject(type) {
        m_cost = costByType(type);
    }

    operator Object();

    long long getCost() const;

    static long long costByType(const ObjectType &type);
};

#endif //LIGHTSED_LOCKED_H
