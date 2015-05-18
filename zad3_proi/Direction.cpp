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

int ForwardDirection::getDistance()
{
	return m_distance;
}

int ExitDirection::getChoice()
{
	return m_choice;
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