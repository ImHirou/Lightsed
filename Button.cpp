#include <SFML/Graphics.hpp>
#include "Button.h"
#include "constants.h"

void Button::setPos1(const Point &p) { m_pos1=p; }
void Button::setPos2(const Point &p) { m_pos2=p; }
void Button::setPos1(int x, int y) { m_pos1.setPos(x, y); }
void Button::setPos2(int x, int y) { m_pos2.setPos(x, y); }
void Button::setPos1(double x, double y) { m_pos1.setPos(x, y); }
void Button::setPos2(double x, double y) { m_pos2.setPos(x, y); }

void Button::setPos(const Point &p1, const Point &p2) {
    setPos1(p1);
    setPos2(p2);
}
void Button::setPos(int x1, int y1, int x2, int y2) {
    setPos1(x1, y1);
    setPos2(x2, y2);
}
void Button::setPos(double x1, double y1, double x2, double y2) {
    setPos1(x1, y1);
    setPos2(x2, y2);
}

void Button::setHovered(bool h) { m_hovered = h; }

Point& Button::getPos1() { return m_pos1; }
Point& Button::getPos2() { return m_pos2; }

bool Button::isCollide(const Point &p) const{
    return (m_pos1.getX()<=p.getX() &&
            m_pos2.getX()>=p.getY() &&
            m_pos1.getY()<=p.getY() &&
            m_pos2.getY()>=p.getY());
}

bool Button::isCollide(int x, int y) const{
    return (m_pos1.getX()<=x &&
            m_pos2.getX()>=x &&
            m_pos1.getY()<=y &&
            m_pos2.getY()>=y);
}
bool Button::isCollide(double x, double y) const{
    return (m_pos1.getX()<=x &&
            m_pos2.getX()>=x &&
            m_pos1.getY()<=y &&
            m_pos2.getY()>=y);
}

bool Button::isHovered() const { return m_hovered; }

void Button::draw(sf::RenderWindow &window, sf::Font& font) {
    float xs = (m_pos2.getX()-m_pos1.getX());
    float ys = (m_pos2.getY()-m_pos1.getY());
    sf::RectangleShape rect(sf::Vector2f(xs, ys), sf::Vector2f());
    sf::Text text;
    text.setFont(font);
    text.setString(m_title);
    text.setCharacterSize(Constants::characterSize);
    text.setPosition(m_pos1.getX()+10, m_pos1.getX()+5);
    if(m_hovered) {
        rect.setOutlineThickness(4);
        rect.setFillColor(sf::Color(30, 30, 30));
        rect.setOutlineColor(sf::Color(170, 170, 170));
        text.setFillColor(sf::Color(30, 30, 170));
    }
    else {
        rect.setOutlineThickness(2);
        rect.setFillColor(sf::Color(50, 50, 50));
        rect.setOutlineColor(sf::Color(160, 160, 160));
        text.setFillColor(sf::Color(200, 200, 200));
    }
    rect.setPosition(m_pos1.getX(), m_pos1.getY());
    window.draw(rect);
    window.draw(text);
}