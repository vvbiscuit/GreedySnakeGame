#ifndef _MAP_H_
#define _MAP_H_

#include "Define.h"

/**********************************************************************************************//**
 * @class	Map
 *
 * @brief	游戏地图类.
 *
 * @author	vvbiscuit
 * @date	2021/7/25
 **************************************************************************************************/
class Map
{
public:
	Map();
	~Map();

	void drawMap();
private:
	int m_mapLength;
};

#endif