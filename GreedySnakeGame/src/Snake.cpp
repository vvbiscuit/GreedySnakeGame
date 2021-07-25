//#include <iostream>

#include "Snake.h"

Snake* Snake::s_instance = nullptr;

Snake::Snake()
{

}

Snake::~Snake()
{

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
