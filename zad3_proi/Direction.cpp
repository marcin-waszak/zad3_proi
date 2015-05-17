#include "Direction.h"

class ForwardDirection
{
	ForwardDirection(int distance) : m_id(0), m_distance(distance)
	{
	}
};

class ExitDirection
{
	ExitDirection(int distance, int choice) : m_id(1), m_distance(distance), m_choice(choice)
	{
	}
};

class LeftDirection
{
	LeftDirection(int distance) : m_id(2), m_distance(distance)
	{
	}
};

class RightDirection
{
	RightDirection(int distance) : m_id(3), m_distance(distance)
	{
	}
};