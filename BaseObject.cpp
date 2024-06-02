#include "BaseObject.h"
#include <SFML/Graphics/Color.hpp>
#include "constants.h"

BaseObject::ObjectType BaseObject::getType() const { return m_type; }
char BaseObject::getChar() const { return m_char; }
const sf::Color &BaseObject::getColor() const { return m_color; }

void BaseObject::setColor(const sf::Color &color) { m_color = color; }

char BaseObject::charByType(const ObjectType &type) {
    switch (type) {
        case EMPTY: return '.';
        case ONE: return '1';
        case TWO: return '2';
        case THREE: return '3';
        case FOUR: return '4';
        case FIVE: return '5';
        case SIX: return '6';
        case SEVEN: return '7';
        case EIGHT: return '8';
        case NINE: return '9';
        case PLAYER: return Constants::playerChar;
        case LIGHT: return 'l';
        default: return ' ';
    }
}

sf::Color BaseObject::colorByType(const ObjectType &type) {
    switch (type) {
        case EMPTY: return {80, 80, 80};
        case ONE: return {30, 40, 120};
        case TWO: return {30, 40, 130};
        case THREE: return {30, 40, 140};
        case FOUR: return {40, 40, 120};
        case FIVE: return {40, 40, 110};
        case SIX: return {50, 40, 120};
        case SEVEN: return {60, 40, 110};
        case EIGHT: return {60, 30, 120};
        case NINE: return {70, 30, 110};
        case PLAYER: return {200, 200, 200};
        case LIGHT: return {170, 170, 230};
        default: return sf::Color(0);
    }
}

BaseObject::ObjectType BaseObject::typeByChar(char ch) {
    switch (ch) {
        case ' ': return EMPTY;
        case '1': return ONE;
        case '2': return TWO;
        case '3': return THREE;
        case '4': return FOUR;
        case '5': return FIVE;
        case '6': return SIX;
        case '7': return SEVEN;
        case '8': return EIGHT;
        case '9': return NINE;
        case Constants::playerChar: return PLAYER;
        case 127: return LIGHT;
        default: return EMPTY;
    }
}