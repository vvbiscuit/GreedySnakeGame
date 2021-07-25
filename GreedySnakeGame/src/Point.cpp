#include <iostream>

#include "Point.h"

using namespace std;

Point::Point()
{

}

Point::Point(const int x, const int y)
	: m_x(x), m_y(y)
{

}

Point::~Point()
{

}

void Point::print()
{

}

void Point::clear()
{

}

void Point::changePosition(const int x, const int y)
{

}

int Point::getX()
{
	return m_x;
}

int Point::getY()
{
	return m_y;
}

bool Point::operator==(const Point& point)
{
	return (point.m_x == this->m_x) && (point.m_y == this->m_y);
}