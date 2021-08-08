#ifndef _POINT_H_
#define _POINT_H_

#include <string>
using namespace std;

/**********************************************************************************************//**
 * @class	Point
 *
 * @brief	点类，用于存储和打印点信息.
 *
 * @author	vvbiscuit
 * @date	2021/7/25
 **************************************************************************************************/
class Point
{
public:
	Point();
	~Point();
	Point(const int x, const int y);

	bool operator== (const Point& point);

	void print(string symbol);
	void changePosition(const int x, const int y);
	void setCursorPosition(const int x, const int y);//设置控制台光标点坐标,光标定位的作用
	int getX();
	int getY();

private:
	int m_x, m_y;
};

#endif // _POINT_H_