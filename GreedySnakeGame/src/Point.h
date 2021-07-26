#ifndef _POINT_H_
#define _POINT_H_

/**********************************************************************************************//**
 * @class	Point
 *
 * @brief	���࣬���ڴ洢�ʹ�ӡ����Ϣ.
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

	void print(char symbol);
	void clear();
	void changePosition(const int x, const int y);

	void setCursorPosition(const int x, const int y);//���ÿ���̨��������,��궨λ������

	int getX();
	int getY();
private:
	int m_x, m_y;
};

#endif // _POINT_H_