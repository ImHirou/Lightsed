#ifndef LIGHTSED_POINT_H
#define LIGHTSED_POINT_H

class Point {
private:
    double m_x;
    double m_y;
public:
    explicit Point(int x=0, int y=0) : m_x(x), m_y(y) { }
    Point(double x, double y) : m_x(x), m_y(y) { }

    void setX(double x);
    void setY(double y);
    void setX(int x);
    void setY(int y);
    double getX() const;
    double getY() const;

    void move(double x, double y);
    void move(int x, int y);
    void move(Point &p);
    void setPos(double x, double y);
    void setPos(int x, int y);
    void setPos(Point &p);

};

#endif //LIGHTSED_POINT_H
