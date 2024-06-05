#include "Button.h"

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

Point& Button::getPos1() { return m_pos1; }
Point& Button::getPos2() { return m_pos2; }

bool Button::isCollide(const Point &p) {
    return (m_pos1.getX()>=p.getX() &&
            m_pos2.getX()<=p.getY() &&
            m_pos1.getY()>=p.getY() &&
            m_pos2.getY()<=p.getY());
}

bool Button::isCollide(int x, int y) {
    return (m_pos1.getX()>=x &&
            m_pos2.getX()<=x &&
            m_pos1.getY()>=y &&
            m_pos2.getY()<=y);
}
bool Button::isCollide(double x, double y) {
    return (m_pos1.getX()>=x &&
            m_pos2.getX()<=x &&
            m_pos1.getY()>=y &&
            m_pos2.getY()<=y);
}