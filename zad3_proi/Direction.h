#ifndef DIRECTION_H
#define DIRECTION_H

//#include <string>

class Direction
{
	int m_id;
	int m_distance;
};

class ForwardDirection : public Direction
{
public:
	ForwardDirection(int distance);
};

class ExitDirection : public Direction
{
public:
	ExitDirection(int distance, int choice);

private:
	int m_choice;
};

class LeftDirection : public Direction
{
public:
	LeftDirection(int distance);
};

class RightDirection : public Direction
{
public:
	RightDirection();
};

#endif