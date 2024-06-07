#ifndef LIGHTSED_BASEOBJECT_H
#define LIGHTSED_BASEOBJECT_H

#include <SFML/Graphics/Color.hpp>

class BaseObject {
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
        LIGHT,
        BUILDING1,
        CHANCE_BUILDING,
        AUTOMATION_BUILDING,
        TOTAL_TYPES

    };
protected:
    ObjectType m_type;
    char m_char;
    sf::Color m_color;
public:
    BaseObject(ObjectType type=ObjectType::EMPTY) : m_type(type){
        m_char = charByType(type);
        m_color = colorByType(type);
    }

    virtual ObjectType getType() const;
    virtual char getChar() const;
    virtual const sf::Color &getColor() const;

    static char charByType(const ObjectType &type);
    static sf::Color colorByType(const ObjectType &type);
    static ObjectType typeByChar(char ch);

    virtual void setColor(const sf::Color &color);
};

#endif //LIGHTSED_BASEOBJECT_H
