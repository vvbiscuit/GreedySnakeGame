#ifndef _FOOD_H_
#define _FOOD_H_

#include "Point.h"

class Food
{
public:
	Food() {}
	~Food() {}

	void produceFood();

private:
	Point m_coordinate;
};
#endif