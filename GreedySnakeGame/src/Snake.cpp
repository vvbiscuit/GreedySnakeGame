//#include <iostream>

#include "Snake.h"
#include "Define.h"

Snake* Snake::s_instance = nullptr;

Snake::Snake()
{
	Point head(MAP_LENGTH / 2, MAP_LENGTH / 2);
	Point body_0(MAP_LENGTH / 2 + 1, MAP_LENGTH / 2);
	Point body_1(MAP_LENGTH / 2 + 2, MAP_LENGTH / 2);
	Point body_2(MAP_LENGTH / 2 + 2, MAP_LENGTH / 2 + 1);
	m_coordinateVec.push_back(head);
	m_coordinateVec.push_back(body_0);
	m_coordinateVec.push_back(body_1);
	m_coordinateVec.push_back(body_2);
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

void Snake::draw()
{
	for (int i = 0; i < m_coordinateVec.size(); i++)
	{
		m_coordinateVec[i].print('*');
	}
}
