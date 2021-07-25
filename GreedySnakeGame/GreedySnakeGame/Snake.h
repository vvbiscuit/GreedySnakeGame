#ifndef _SNAKE_H_
#define _SNAKE_H_

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

	void draw();			//�����ߺ���

	bool isEatSelf();		//�ж��Ƿ�Ե��Լ�
	bool isHitWall();		//�ж��Ƿ�ײ��ǽ
	bool isSnakeAlive();	//�ж��߱����Ƿ���

private:
	Snake();
	~Snake();

	static Snake* s_instance;
};

#endif
