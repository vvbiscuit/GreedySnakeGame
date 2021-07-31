#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>

#include "Map.h"
#include "Point.h"
#include "Snake.h"
#include "Food.h"

using namespace std;

//���ع��
void hideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//����һ���Ϸ�ʳ������������غ�
void produceValidFood(Food &food, std::vector<Point> vec)
{
	while (1)
	{
		food.produceFood();
		bool isFoodValid = true;
		for (int i = 0; i < vec.size(); i++)
		{
			if (food.getCoordinate() == vec[i])
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

int main()
{
	system("mode con cols=88 lines=40");	//���ÿ���̨���ڴ�С
	system("title ̰����");					//���ñ���
	hideCursor();							//���ع��

	Map gameMap;
	gameMap.drawMap();						//��ͼ����

	Snake::getInstance()->draw();			//�߶������
	Food food;
	produceValidFood(food, Snake::getInstance()->getSnakeCoorVec());	//�����ƶ�ǰ����һ���Ϸ���ʳ��λ��

	while (true)
	{
		int rtn = Snake::getInstance()->move(food);
		if (rtn == 0)
		{
			cout << "Game over" << endl;
			break;
		}

		Sleep(200);
	}

	//Point myPoint;
	//myPoint.setPosition(10, 8);
	//cout << "t";

	getchar();

	return 0;
}