#include <ctime>

#include "Food.h"
#include "Define.h"

void Food::produceFood()
{
	srand(time(0));

	int x = 1;
	int y = 1;

	while (x % 2 != 0)
	{
		x = rand() % (MAP_LENGTH * 2 - 4) + 2;
		y = rand() % (MAP_LENGTH - 3) + 1;
	}

	m_coordinate.setCursorPosition(x, y);
	m_coordinate.print("бя");
}

Point Food::getCoordinate()
{
	return m_coordinate;
}
