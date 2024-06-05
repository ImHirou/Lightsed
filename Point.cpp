#include "Point.h"

void Point::setX(double x) { m_x=x; }
void Point::setY(double y) { m_x=y; }
void Point::setX(int x) { m_x=x; }
void Point::setY(int y) { m_x=y; }

double Point::getX() const { return m_x; }
double Point::getY() const { return m_y; }

void Point::move(int x, int y) { m_x+=x; m_y+=y; }
void Point::move(double x, double y) { m_x+=x; m_y+=y; }
void Point::move(Point &p) { m_x+=p.m_x; m_y+=p.m_y; }
void Point::setPos(int x, int y) { m_x=x; m_y=y; }
void Point::setPos(double x, double y) { m_x=x; m_y=y; }
void Point::setPos(Point &p) { m_x=p.m_x; m_y=p.m_y; }
