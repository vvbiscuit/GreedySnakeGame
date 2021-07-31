#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <vector>

#include "Point.h"
#include "Food.h"

/**********************************************************************************************//**
 * @class	Snake
 *
 * @brief	̰�����࣬�������ɾ������Ϸ����.
 *
 * @author	vvbiscuit
 * @date	2021/7/25
 **************************************************************************************************/
class Snake
{
public:
	static Snake* getInstance();
	static void finalizeInstance();

	void draw();			
	int move(Food &food);			
	Point getDirection();	//��ȡ�û����̲����ķ��򣬷����µ���ͷ����
	std::vector<Point> getSnakeCoorVec();

	bool isEatSelf();		//�ж��Ƿ�Ե��Լ�
	bool isHitWall();		//�ж��Ƿ�ײ��ǽ
	bool isSnakeAlive();	//�ж��߱����Ƿ���

private:
	Snake();
	~Snake();
	void getHeadCoor(int &x,int &y);	//��ȡ��ͷ������

	static Snake* s_instance;
	bool m_isAlive;
	std::vector<Point> m_coordinateVec;	//�������������
};

#endif
