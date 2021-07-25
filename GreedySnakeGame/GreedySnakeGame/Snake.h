#ifndef _SNAKE_H_
#define _SNAKE_H_

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

	void draw();			//绘制蛇函数

	bool isEatSelf();		//判断是否吃到自己
	bool isHitWall();		//判断是否撞到墙
	bool isSnakeAlive();	//判断蛇本身是否存活

private:
	Snake();
	~Snake();

	static Snake* s_instance;
};

#endif
