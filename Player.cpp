#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Building.h"
#include "constants.h"

bool Player::isNXBoost() { return m_NXBoost; }
int Player::getX() const { return m_x; }
int Player::getY() const { return m_y; }
int Player::getLightChance() const { return m_lightChance; }
long long Player::getLight() const { return m_light; }
long long Player::getMulti() const { return m_multi; }
Automator& Player::getAutomator() { return m_automator; }

void Player::setNXBoost(bool tb) { m_NXBoost = tb; }
void Player::reduceLight(long long n) { m_light-=n; }
void Player::addLight(long long n) { m_light+=n; }
void Player::addMulti(long long n) { m_multi+=n; }

void Player::collectLight(int x, int y, Cell &cell) {
    if(cell.isLight()) {
        if(isNXBoost()) m_light += m_multi*BaseObject::typeByChar(Constants::mapLayer2[x][y]);
        else m_light += m_multi;
        cell.makeEmpty();
    }
}

bool Player::isKeyPressed(Player::Key key) const { return m_keyPressed[key]; }

void Player::setKey(Player::Key key, bool p) { m_keyPressed[key] = p;}
void Player::setMulti(long long mult) { m_multi = mult; }
void Player::setLightChance(int c) { m_lightChance = c;}

void Player::draw(sf::RenderWindow &window, int x, int y, sf::Font &font) {
    sf::Text text;
    text.setFont(font);
    text.setString(Constants::playerChar);
    text.setCharacterSize(Constants::characterSize);
    text.setPosition(x*Constants::characterSize, y*Constants::characterSize);
    text.setColor(BaseObject::colorByType(BaseObject::PLAYER));
    window.draw(text);
}

void Player::moveBy(int x, int y, Cell &cell) {
    if(cell.isLocked()) {
        if(cell.canUnlockCell(*this)) {
            cell.unlockCell(*this);
        }
    }
    else {
        if(cell.isBuilding()) {
            Building* building = dynamic_cast<Building*>(cell.getLayer1());
            building->getTab().setOpen(!building->getTab().isOpen());
        }
        else {
            collectLight(m_y+y, m_x+x, cell);
            m_x += x;
            m_y += y;
        }
    }
    std::cout << m_light << "\n";
}