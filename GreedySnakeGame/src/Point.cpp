#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>

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

void Point::print(string symbol)
{
	setCursorPosition(m_x, m_y);
	cout << symbol;
}

void Point::changePosition(const int x, const int y)
{
	m_x = x;
	m_y = y;
}

void Point::setCursorPosition(const int x, const int y)
{
	changePosition(x, y);
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);//这个就是这样，记住格式就行
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