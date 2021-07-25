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
	for (int row = 0; row < m_mapLength; row++)//��
	{
		for (int col = 0; col < m_mapLength; col++)//��
		{
			if (row == 0 || (row == m_mapLength - 1))//���к����һ��
			{
				cout << "$";
			}
			else if (col == 0 || (col == m_mapLength - 1))
			{
				cout << "$";
			}
			else
			{
				cout << " ";
			}

			if (col == m_mapLength - 1)
			{
				cout << endl;
			}
		}
	}
}
