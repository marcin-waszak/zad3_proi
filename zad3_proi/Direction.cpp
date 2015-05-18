#include "Direction.h"
#include <iostream>

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

void ForwardDirection::accept(Visitor *v)
{
	v->visit(this);
}

void ExitDirection::accept(Visitor *v)
{
	v->visit(this);
}

void LeftDirection::accept(Visitor *v)
{
	v->visit(this);
}

void RightDirection::accept(Visitor *v)
{
	v->visit(this);
}

void ForwardDirection::print()
{
	std::cout << "Forward: " << m_distance << std::endl;
}

void ExitDirection::print()
{
	std::cout << "Exit #" << m_choice << std::endl;
}

void LeftDirection::print()
{
	std::cout << "Left" << std::endl;
}

void RightDirection::print()
{
	std::cout << "Right" << std::endl;
}