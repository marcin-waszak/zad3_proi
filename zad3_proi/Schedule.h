#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include "Direction.h"

class Schedule
{
public:
	~Schedule();
	void addForward(int distance);
	void addExit(int choice);
	void addLeft();
	void addRight();
	void insertForward(size_t position, int distance);
	void insertExit(size_t position, int choice);
	void insertLeft(size_t position);
	void insertRight(size_t position);
	void erase(size_t position);

protected:
	std::vector<Direction*> m_vector;
};

#endif