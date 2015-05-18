#ifndef DIRECTION_H
#define DIRECTION_H

#include "Visitor.h"

class Direction
{
public:
	enum Type {D_FORWARD, D_EXIT, D_LEFT, D_RIGHT};
	virtual void accept(class Visitor*) = 0;

protected:
	int m_type;
};

class ForwardDirection : public Direction
{
public:
	ForwardDirection(int distance);
	int getDistance();
	void accept(Visitor*);

protected:
	int m_distance;
};

class ExitDirection : public Direction
{
public:
	ExitDirection(int choice);
	int getChoice();
	void accept(Visitor*);

protected:
	int m_choice;
};

class LeftDirection : public Direction
{
public:
	LeftDirection();
	void accept(Visitor*);
};

class RightDirection : public Direction
{
public:
	RightDirection();
	void accept(Visitor*);
};

#endif