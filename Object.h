#ifndef LIGHTSED_OBJECT_H
#define LIGHTSED_OBJECT_H

#include <SFML/Graphics/Color.hpp>

class Object {
public:
    enum ObjectType {
        EMPTY,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        PLAYER,
        TOTAL_TYPES

    };
private:
    ObjectType m_type;
    char m_char;
    sf::Color m_color;
public:
    Object(ObjectType type=Object::EMPTY) : m_type(type) {
        m_char = charByType(type);
        m_color = colorByType(type);
    }

    ObjectType getType() const;
    char getChar() const;
    const sf::Color &getColor() const;

    static char charByType(const ObjectType &type);
    static sf::Color colorByType(const ObjectType &type);
    static ObjectType typeByChar(char ch);

};

#endif //LIGHTSED_OBJECT_H
