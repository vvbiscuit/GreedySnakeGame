#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <vector>

#include "Point.h"
#include "Food.h"

/**********************************************************************************************//**
 * @class	Snake
 *
 * @brief	贪吃蛇类，用于生成具体的游戏对象.
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
	Point getDirection();	//获取用户键盘操作的方向，返回新的蛇头方向
	std::vector<Point> getSnakeCoorVec();

	bool isEatSelf();		//判断是否吃到自己
	bool isHitWall();		//判断是否撞到墙
	bool isSnakeAlive();	//判断蛇本身是否存活

private:
	Snake();
	~Snake();
	void getHeadCoor(int &x,int &y);	//获取蛇头的坐标

	static Snake* s_instance;
	bool m_isAlive;
	std::vector<Point> m_coordinateVec;	//蛇身的坐标序列
};

#endif
