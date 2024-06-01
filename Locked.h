#ifndef LIGHTSED_LOCKED_H
#define LIGHTSED_LOCKED_H
#include "Object.h"

class Locked : public Object {
private:
    long long m_cost;
public:
    Locked(ObjectType type=ObjectType::EMPTY) : Object(type) {
        m_cost = costByType(type);
    }

    long long getCost() const;

    long long costByType(const ObjectType &type) const;
};

#endif //LIGHTSED_LOCKED_H
