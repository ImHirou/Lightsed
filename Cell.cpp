#include "Cell.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "constants.h"
#include <cmath>
#include <iostream>

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
    if(lightLevel<=0) {
        m_layer1.setColor(sf::Color(2, 2, 2));
        m_layer2.setColor(sf::Color(2, 2, 2));
        return;
    }
    sf::Color baseColor = Object::colorByType(m_layer2.getType());
    double r = (baseColor.r * sqrt(lightLevel)) / (log2(baseColor.r) / (log10(lightLevel+1))+1);
    double g = (baseColor.g * sqrt(lightLevel)) / (log2(baseColor.g) / (log10(lightLevel+1))+1);
    double b = (baseColor.b * sqrt(lightLevel)) / (log2(baseColor.b) / (log10(lightLevel+1))+1);
    if(r > 255) r = 255;
    if(g > 255) g = 255;
    if(b > 255) b = 255;
    if(r < 0) r = 2;
    if(g < 0) g = 2;
    if(b < 0) b = 2;
    m_layer2.setColor(sf::Color(r,g,b));
}