#ifndef DIRECTION_H
#define DIRECTION_H

class Direction
{
public:
	enum Type {D_FORWARD, D_EXIT, D_LEFT, D_RIGHT};

protected:
	int m_type;
};

class ForwardDirection : public Direction
{
public:
	ForwardDirection(int distance);

protected:
	int m_distance;
};

class ExitDirection : public Direction
{
public:
	ExitDirection(int choice);

protected:
	int m_choice;
};

class LeftDirection : public Direction
{
public:
	LeftDirection();
};

class RightDirection : public Direction
{
public:
	RightDirection();
};

#endif