#include "Locked.h"

long long Locked::getCost() const { return m_cost; }

long long Locked::costByType(const BaseObject::ObjectType &type) {
    switch (type) {
        case ONE: return    1;
        case TWO: return    10;
        case THREE: return  100;
        case FOUR: return   1000;
        case FIVE: return   10000;
        case SIX: return    100000;
        case SEVEN: return  1000000;
        case EIGHT: return  10000000;
        case NINE: return   100000000;
        default: return 0;
    }
}