#include "Cell.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "constants.h"
#include <cmath>
#include "BaseObject.h"
#include "Light.h"

Cell::Cell() {
    m_layer1 = std::make_unique<BaseObject>();
    m_layer2 = std::make_unique<BaseObject>();
}

bool Cell::canUnlockCell(const Player &player){
    Locked* lock = dynamic_cast<Locked*>(m_layer2.get());
    if(!lock) return false;
    return player.getLight() >= lock->getCost();
}

bool Cell::isLocked() const {
    switch (m_layer2->getType()) {
        case BaseObject::ONE:
        case BaseObject::TWO:
        case BaseObject::THREE:
        case BaseObject::FOUR:
        case BaseObject::FIVE:
        case BaseObject::SIX:
        case BaseObject::SEVEN:
        case BaseObject::EIGHT:
        case BaseObject::NINE:
            return true;
        default:
            return false;
    }
}

bool Cell::isLight() const {
    return m_layer2->getType() == BaseObject::LIGHT;
}

void Cell::unlockCell(Player &player) {
    if(!isLocked()) return;
    Locked* lock = dynamic_cast<Locked*>(m_layer2.get());
    player.reduceLight(lock->getCost());
    m_layer2 = std::make_unique<BaseObject>();
}

void Cell::drawCell(sf::RenderWindow &window, int x, int y, sf::Font &font) {
    sf::Text text;
    text.setFont(font);
    if(isLocked() || isLight()) {
        text.setString(m_layer2->getChar());
        text.setCharacterSize(Constants::characterSize);
        text.setPosition(x * Constants::characterSize, y * Constants::characterSize);
        text.setColor(m_layer2->getColor());
    }
    else {
        text.setString(m_layer1->getChar());
        text.setCharacterSize(Constants::characterSize);
        text.setPosition(x * Constants::characterSize, y * Constants::characterSize);
        text.setColor(m_layer1->getColor());
    }
    window.draw(text);
}

void Cell::changeLightLevel(int lightLevel) {
    if(m_layer2->getType() == BaseObject::LIGHT) return;
    if(lightLevel<=0) {
        m_layer1->setColor(sf::Color(2, 2, 2));
        m_layer2->setColor(sf::Color(2, 2, 2));
        return;
    }
    sf::Color baseColor = BaseObject::colorByType(m_layer2->getType());
    double r = (baseColor.r * sqrt(lightLevel)) / (log2(baseColor.r) / (log10(lightLevel+1))+1);
    double g = (baseColor.g * sqrt(lightLevel)) / (log2(baseColor.g) / (log10(lightLevel+1))+1);
    double b = (baseColor.b * sqrt(lightLevel)) / (log2(baseColor.b) / (log10(lightLevel+1))+1);
    if(r > 255) r = 255;
    if(g > 255) g = 255;
    if(b > 255) b = 255;
    if(r < 0) r = 2;
    if(g < 0) g = 2;
    if(b < 0) b = 2;
    m_layer1->setColor(sf::Color(r,g,b));
    m_layer2->setColor(sf::Color(r,g,b));
}

void Cell::makeEmpty() {
    m_layer2 = std::make_unique<BaseObject>();
}

void Cell::makeLight() {
    m_layer2 = std::make_unique<Light>();
}
