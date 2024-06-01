#include "Cell.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "constants.h"

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