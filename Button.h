#ifndef LIGHTSED_BUTTON_H
#define LIGHTSED_BUTTON_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include "Point.h"

class Button {
protected:
    std::string m_title;
    Point m_pos1;
    Point m_pos2;
    bool m_hovered;
public:
    Button(Point& p1, Point& p2, const std::string &title) : m_pos1(p1), m_pos2(p2), m_title(title) {}
    Button(double x1, double y1, double x2, double y2, const std::string &title) : m_pos1(x1, y1), m_pos2(x2, y2), m_title(title) {}
    Button(int x1, int y1, int x2, int y2, const std::string &title) : m_pos1(x1, y1), m_pos2(x2, y2), m_title(title) {}
    Button() : m_pos1(), m_pos2(), m_title("") {}

    void setPos1(const Point& p);
    void setPos1(int x, int y);
    void setPos1(double x, double y);

    void setPos2(const Point& p);
    void setPos2(int x, int y);
    void setPos2(double x, double y);

    void setPos(const Point& p1, const Point& p2);
    void setPos(int x1, int y1, int x2, int y2);
    void setPos(double x1, double y1, double x2, double y2);

    void setHovered(bool h);

    Point& getPos1();
    Point& getPos2();

    bool isCollide(const Point& p) const;
    bool isCollide(int x, int y) const;
    bool isCollide(double x, double y) const;
    bool isHovered() const;

    virtual void draw(sf::RenderWindow &window, sf::Font &font);

};

#endif //LIGHTSED_BUTTON_H
