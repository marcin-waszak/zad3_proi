#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>
#include "Direction.h"

class Schedule
{
public:
	~Schedule();
	void addForward(int distance); // const int dist. ?
	void addExit(int choice);
	void addLeft();
	void addRight();
	void insertForward(size_t position, int distance);
	void insertExit(size_t position, int choice);
	void insertLeft(size_t position);
	void insertRight(size_t position);
	void erase(size_t position);
	void printAll();
	void saveFile(std::string fileName);

	void accept(Visitor *visitor);

private:
	std::vector<Direction*> m_vector;
};

#endif