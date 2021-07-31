#include <conio.h>

#include "Snake.h"
#include "Define.h"

Snake* Snake::s_instance = nullptr;

enum Direction
{
	//���̻�ȡ����������ASCII��ֵ
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

	//��ȡ��ͷ������
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
	m_coordinateVec[0].print("��");//��ͷ��־
	for (int i = 1; i < m_coordinateVec.size(); i++)
	{
		m_coordinateVec[i].print("��");
	}
}

int Snake::move(Food& food)
{
	Point newHeadPoint = getDirection();
	m_coordinateVec.insert(m_coordinateVec.begin(), newHeadPoint);
	m_coordinateVec.back().print("  ");//����β�������ÿ��ַ������ԭ�ȵĴ�ӡ
	m_coordinateVec.pop_back();//��ԭ��βԪ������
	draw();

	//����ͷ�����ʳ������һ�£���Ϊ�Ե�ʳ��
	if (newHeadPoint == food.getCoordinate())
	{
		//����һ����ʳ��
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
	static int key = LEFT;  //��̬������ֹ�ı��ƶ���������¸Ļ���

	if (_kbhit())
	{
		int user_input = _getch();//��ȡ�û��Ӽ�������ķ�����������Ҫ������_getch
		user_input = _getch();

		switch (user_input)     //�����ʱ������ֵΪwasd�е�һ������ֵ��key
		{
		default:
			break;   //default��ȱʡ�����ֻ���κ���������ƥ�������²Ż�ִ�� ����д��ǰ�棡��Ȼ���޷�ת��
		case LEFT:
		case RIGHT:
		case UP:
		case DOWN:

			//���temp�ķ����key�ķ����෴��ֵ  ��Ϊ�����ƶ��������෴  ��������Ϊ��ʼ������
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
	//��ȡ��ͷ������
	int head_x = 0;
	int head_y = 0;
	getHeadCoor(head_x, head_y);

	for (int i = 1; i < m_coordinateVec.size(); i++)//��1��ʼ�������Լ�����ͷ�Ƚ�
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
	//��ȡ��ͷ������
	int head_x = 0;
	int head_y = 0;
	getHeadCoor(head_x, head_y);

	//�ж�ײǽ��������x����y������һ���ڱ߽�
	if (head_x <= 0 || (head_x >= 2 * MAP_LENGTH - 3)) //x�����ڴ�ӡԭ����Ҫ��2
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
