#include "Direction.h"

ForwardDirection::ForwardDirection(int distance)
{
	m_type = D_FORWARD;
	m_distance = distance;
}

ExitDirection::ExitDirection(int choice)
{
	m_type = D_EXIT;
	m_choice = choice;
}

LeftDirection::LeftDirection()
{
	m_type = D_LEFT;
}

RightDirection::RightDirection()
{
	m_type = D_RIGHT;
}