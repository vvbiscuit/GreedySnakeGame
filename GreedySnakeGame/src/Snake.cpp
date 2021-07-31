#include <conio.h>

#include "Snake.h"
#include "Define.h"

Snake* Snake::s_instance = nullptr;

enum Direction
{
	//键盘获取方向键输入的ASCII码值
	LEFT = 75,
	UP = 72,
	RIGHT = 77,
	DOWN = 80
};

Snake::Snake()
{
	Point head(MAP_LENGTH / 2, MAP_LENGTH / 2);
	Point body_0(MAP_LENGTH / 2 + 2, MAP_LENGTH / 2);
	Point body_1(MAP_LENGTH / 2 + 4, MAP_LENGTH / 2);
	Point body_2(MAP_LENGTH / 2 + 4, MAP_LENGTH / 2 + 1);
	m_coordinateVec.push_back(head);
	m_coordinateVec.push_back(body_0);
	m_coordinateVec.push_back(body_1);
	m_coordinateVec.push_back(body_2);

	m_isAlive = true;
}

Snake::~Snake()
{

}

void Snake::getHeadCoor(int& x, int& y)
{
	if (m_coordinateVec.empty())
	{
		return;
	}

	//获取蛇头的坐标
	x = m_coordinateVec.front().getX();
	y = m_coordinateVec.front().getY();
}

Snake* Snake::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new Snake();
	}

	return s_instance;
}

void Snake::finalizeInstance()
{
	if (s_instance != nullptr)
	{
		delete s_instance;
		s_instance = nullptr;
	}

	return;
}

void Snake::draw()
{
	m_coordinateVec[0].print("●");//蛇头标志
	for (int i = 1; i < m_coordinateVec.size(); i++)
	{
		m_coordinateVec[i].print("■");
	}
}

int Snake::move(Food& food)
{
	Point newHeadPoint = getDirection();
	m_coordinateVec.insert(m_coordinateVec.begin(), newHeadPoint);
	m_coordinateVec.back().print("  ");//将队尾的蛇身用空字符串清除原先的打印
	m_coordinateVec.pop_back();//将原队尾元素舍弃
	draw();

	//若蛇头坐标和食物坐标一致，即为吃到食物
	if (newHeadPoint == food.getCoordinate())
	{
		//生成一个新食物
		while (1)
		{
			food.produceFood();
			bool isFoodValid = true;
			for (int i = 0; i < m_coordinateVec.size(); i++)
			{
				if (food.getCoordinate() == m_coordinateVec[i])
				{
					isFoodValid = false;
				}
			}
			if (isFoodValid)
			{
				break;
			}
		}
	}

	if (isEatSelf() || isHitWall())
	{
		return 0;
	}

	return 1;
}

Point Snake::getDirection()
{
	static int key = LEFT;  //静态变量防止改变移动方向后重新改回来

	if (_kbhit())
	{
		int user_input = _getch();//获取用户从键盘输入的方向键，方向键要做两次_getch
		user_input = _getch();

		switch (user_input)     //如果临时变量的值为wasd中的一个，则赋值给key
		{
		default:
			break;   //default是缺省情况，只有任何条件都不匹配的情况下才会执行 必须写在前面！不然蛇无法转向
		case LEFT:
		case RIGHT:
		case UP:
		case DOWN:

			//如果temp的方向和key的方向不相反则赋值  因为两次移动方向不能相反  将蛇设置为初始向右走
			if ((key == LEFT && user_input != RIGHT) || (key == RIGHT && user_input != LEFT)
				|| (key == UP && user_input != DOWN) || (key == DOWN && user_input != UP))
			{
				key = user_input;
			}
			break;
		}
	}

	Point newHeadPoint;
	switch (key)
	{
	case LEFT:
	{
		newHeadPoint.setCursorPosition(m_coordinateVec.front().getX() - 2, m_coordinateVec.front().getY());
		break;
	}

	case RIGHT:
	{
		newHeadPoint.setCursorPosition(m_coordinateVec.front().getX() + 2, m_coordinateVec.front().getY());
		break;
	}
	case UP:
	{
		newHeadPoint.setCursorPosition(m_coordinateVec.front().getX(), m_coordinateVec.front().getY() - 1);
		break;
	}
	case DOWN:
	{
		newHeadPoint.setCursorPosition(m_coordinateVec.front().getX(), m_coordinateVec.front().getY() + 1);
		break;
	}
	}

	return newHeadPoint;
}

std::vector<Point> Snake::getSnakeCoorVec()
{
	return m_coordinateVec;
}

bool Snake::isEatSelf()
{
	//获取蛇头的坐标
	int head_x = 0;
	int head_y = 0;
	getHeadCoor(head_x, head_y);

	for (int i = 1; i < m_coordinateVec.size(); i++)//从1开始，不与自己的蛇头比较
	{
		if (head_x == m_coordinateVec[i].getX() && head_y == m_coordinateVec[i].getY())
		{
			m_isAlive = false;
			return true;
		}
	}

	return false;
}

bool Snake::isHitWall()
{
	//获取蛇头的坐标
	int head_x = 0;
	int head_y = 0;
	getHeadCoor(head_x, head_y);

	//判断撞墙的条件：x或者y其中有一个在边界
	if (head_x <= 0 || (head_x >= 2 * MAP_LENGTH - 3)) //x轴由于打印原因需要乘2
	{
		m_isAlive = false;
		return true;
	}
	if (head_y <= 0 || (head_y >= MAP_LENGTH - 1))
	{
		m_isAlive = false;
		return true;
	}

	return false;
}

bool Snake::isSnakeAlive()
{
	return m_isAlive;
}
