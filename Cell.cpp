#include "Cell.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "constants.h"
#include <cmath>

Cell::Cell() {
    m_layer1 = Object();
    m_layer2 = Locked();
}

bool Cell::canUnlockCell(const Player &player) const {
    return player.getLight() >= m_layer2.getCost();
}

bool Cell::isLocked() const {
    return m_layer2.getType() != Object::EMPTY;
}

void Cell::unlockCell(Player &player) {
    if(!isLocked()) return;
    player.reduceLight(m_layer2.getCost());
    m_layer2 = Locked();
}

void Cell::drawCell(sf::RenderWindow &window, int x, int y, sf::Font &font) {
    sf::Text text;
    text.setFont(font);
    text.setString(m_layer2.getChar());
    text.setCharacterSize(Constants::characterSize);
    text.setPosition(x*Constants::characterSize, y*Constants::characterSize);
    text.setColor(m_layer2.getColor());
    window.draw(text);
}

void Cell::changeLightLevel(int lightLevel) {
    if(lightLevel<0) {
        m_layer1.setColor(sf::Color(5, 5, 5));
        m_layer2.setColor(sf::Color(5, 5, 5));
        return;
    }
    sf::Color baseColor = Object::colorByType(m_layer2.getType());
    int r=baseColor.r-(baseColor.r/(lightLevel+1))+lightLevel;
    int g=baseColor.g-(baseColor.g/(lightLevel+1))+lightLevel;
    int b=baseColor.b-(baseColor.b/(lightLevel+1))+lightLevel;
    if(r>255) r=255;
    if(g>255) g=255;
    if(b>255) b=255;
    m_layer2.setColor(sf::Color(r,g,b));
}