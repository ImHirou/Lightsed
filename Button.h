#ifndef LIGHTSED_BUTTON_H
#define LIGHTSED_BUTTON_H

#include "Point.h"

class Button {
protected:
    Point m_pos1;
    Point m_pos2;
public:
    Button(Point& p1, Point& p2) : m_pos1(p1), m_pos2(p2) {}
    Button(double x1, double y1, double x2, double y2) : m_pos1(x1, y1), m_pos2(x2, y2) {}
    Button(int x1, int y1, int x2, int y2) : m_pos1(x1, y1), m_pos2(x2, y2) {}
    Button() : m_pos1(), m_pos2() {}

    void setPos1(const Point& p);
    void setPos1(int x, int y);
    void setPos1(double x, double y);

    void setPos2(const Point& p);
    void setPos2(int x, int y);
    void setPos2(double x, double y);

    void setPos(const Point& p1, const Point& p2);
    void setPos(int x1, int y1, int x2, int y2);
    void setPos(double x1, double y1, double x2, double y2);

    Point& getPos1();
    Point& getPos2();

    bool isCollide(const Point& p);
    bool isCollide(int x, int y);
    bool isCollide(double x, double y);

};

#endif //LIGHTSED_BUTTON_H
