#include "Object.h"

Object::operator Locked() {
    return Locked(m_type);
}

Object::operator Light() {
    return Light();
}