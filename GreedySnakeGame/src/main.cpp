#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>

#include "Map.h"
#include "Point.h"
#include "Snake.h"
#include "Food.h"

using namespace std;

//隐藏光标
void hideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//生成一个合法食物，不能与蛇身重合
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
	system("mode con cols=88 lines=40");	//设置控制台窗口大小
	system("title 贪吃蛇");					//设置标题
	hideCursor();							//隐藏光标

	Map gameMap;
	gameMap.drawMap();						//地图绘制

	Snake::getInstance()->draw();			//蛇对象绘制
	Food food;
	produceValidFood(food, Snake::getInstance()->getSnakeCoorVec());	//在蛇移动前生成一个合法的食物位置

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