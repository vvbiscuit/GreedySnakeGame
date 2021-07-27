#include <iostream>
#include <iomanip>

#include "Map.h"

using namespace std;

Map::Map()
{
	m_mapLength = MAP_LENGTH;
}

Map::~Map()
{

}

void Map::drawMap()
{
	//绘制地图
	// 注意列乘以2的原因，是因为控制台里y=2x才能绘制出正方形，一个纵坐标的值等于两个横坐标的值
	for (int row = 0; row < m_mapLength; row++)//行
	{
		for (int col = 0; col < m_mapLength * 2; col++)//列
		{
			if (row == 0 || (row == m_mapLength - 1))//首行和最后一行
			{
				cout << "$";
			}
			else if (col == 0 || (col == m_mapLength * 2 - 1))
			{
				cout << "$";
			}
			else
			{
				cout << " ";
			}

			if (col == m_mapLength * 2 - 1)
			{
				cout << endl;
			}
		}
	}
}
