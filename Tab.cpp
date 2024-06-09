#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tab.h"
#include "constants.h"

Button** Tab::getButtons() { return m_buttons; }
int Tab::getButtonsNum() const { return m_totalButtons; }
Point& Tab::getPos1() { return m_pos1; }
Point& Tab::getPos2() { return m_pos2; }
bool Tab::isOpen() const { return m_open; }

int Tab::buttonsNumByType(BaseObject::ObjectType type) {
    std::cout << type << "TYPE\n";
    switch (type) {
        case BaseObject::BUILDING1:             return 4;
        case BaseObject::CHANCE_BUILDING:       return 1;
        case BaseObject::AUTOMATION_BUILDING:   return 1;
        default: return 0;
    }
}

void Tab::initButtonsByType(BaseObject::ObjectType type) {
    m_buttons = new Button*[m_totalButtons];
    if(type == BaseObject::BUILDING1) {
        m_buttons[0] = new UpgradeButton((m_pos1.getX()+10), (m_pos1.getY()+100), (190+m_pos1.getX()), (200+m_pos1.getY()), "Doubler", 10, 100, Upgrade1Build1Func);
        m_buttons[1] = new UpgradeButton((m_pos1.getX()+210), (m_pos1.getY()+100), (390+m_pos1.getX()), (200+m_pos1.getY()), "light*Ncell", 200, 1, Upgrade2Build1Func);
        m_buttons[2] = new UpgradeButton((m_pos1.getX()+10), (m_pos1.getY()+210), (190+m_pos1.getX()), (310+m_pos1.getY()), "Ctrl =)", 5000, 1, Upgrade3Build1Func);
        m_buttons[3] = new UpgradeButton((m_pos1.getX()+210), (m_pos1.getY()+210), (390+m_pos1.getX()), (310+m_pos1.getY()), "Shift...", 69000, 1, Upgrade4Build1Func);
    }
    else if(type == BaseObject::CHANCE_BUILDING) {
        m_buttons[0] = new UpgradeButton(m_pos1.getX()+20, m_pos1.getY()+100, 380+m_pos1.getX(), 300+m_pos1.getY(), "Double Light Chance", 1000, 10, UpgradeChanceFunc);
    }
    else if(type == BaseObject::AUTOMATION_BUILDING) {
        m_buttons[0] = new UpgradeButton(m_pos1.getX()+20, m_pos1.getY()+100, 380+m_pos1.getX(), 300+m_pos1.getY(), "Automator", 100, 10, UpgradeAutomatorFunc);
    }
}

void Tab::setOpen(bool o) { m_open = o; }

void Tab::draw(sf::RenderWindow &window, sf::Font &font) {
    float xs = (m_pos2.getX()-m_pos1.getX());
    float ys = (m_pos2.getY()-m_pos1.getY());

    sf::RectangleShape rect(sf::Vector2f(xs, ys));
    rect.setOutlineThickness(2);
    rect.setFillColor(sf::Color(50, 50, 50));
    rect.setOutlineColor(sf::Color(160, 160, 160));
    rect.setPosition(m_pos1.getX(), m_pos1.getY());

    sf::Text text;
    text.setFont(font);
    text.setString(m_title);
    text.setCharacterSize(Constants::characterSize);
    text.setPosition(m_pos1.getX()+10+Constants::characterSize, m_pos1.getX()+5+Constants::characterSize);
    text.setFillColor(sf::Color(200, 200, 200));

    window.draw(rect);
    window.draw(text);
    for(int i=0; i<m_totalButtons; i++) {
        m_buttons[i]->draw(window, font);
    }
}

void Tab::checkHover(int x, int y) {
    for(int i=0; i<m_totalButtons; i++) {
        m_buttons[i]->setHovered(m_buttons[i]->isCollide(x, y));
    }
}