#include "Player.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int Player::getX() const { return m_x; }
int Player::getY() const { return m_y; }
long long Player::getLight() const { return m_light; }

void Player::reduceLight(long long n) { m_light-=n; }

bool Player::isKeyPressed(Player::Key key) const { return m_keyPressed[key]; }

void Player::setKey(Player::Key key, bool p) { m_keyPressed[key] = p;}

void Player::draw(sf::RenderWindow &window, int x, int y, sf::Font &font) {
    sf::Text text;
    text.setFont(font);
    text.setString(Constants::playerChar);
    text.setCharacterSize(Constants::characterSize);
    text.setPosition(x*Constants::characterSize, y*Constants::characterSize);
    text.setColor(Object::colorByType(ObjectType::PLAYER));
    window.draw(text);
}

void Player::moveBy(int x, int y, Cell &cell) {
    std::cout << cell.isLocked() << "\n";
    if(cell.isLocked()) {
        if(cell.canUnlockCell(*this)) {
            cell.unlockCell(*this);
        }
    }
    else {
        m_x += x;
        m_y += y;
    }
}