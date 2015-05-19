#include "Schedule.h"
#include <algorithm>
#include <functional>

Schedule::~Schedule()
{
	size_t vectorSize = m_vector.size();
	
	for(size_t i = 0; i < vectorSize; i++)
		erase(vectorSize - i - 1);
}

void Schedule::addForward(int distance)
{
	Direction* p_direction;
	p_direction = new ForwardDirection(distance);

	m_vector.push_back(p_direction);
}

void Schedule::addExit(int choice)
{
	Direction* p_direction;
	p_direction = new ExitDirection(choice);

	m_vector.push_back(p_direction);
}

void Schedule::addLeft()
{
	Direction* p_direction;
	p_direction = new LeftDirection();

	m_vector.push_back(p_direction);
}

void Schedule::addRight()
{
	Direction* p_direction;
	p_direction = new RightDirection();

	m_vector.push_back(p_direction);
}

void Schedule::insertForward(size_t position, int distance)
{
	Direction* p_direction;
	p_direction = new ForwardDirection(distance);

	m_vector.insert(m_vector.begin() + position, p_direction);
}

void Schedule::insertExit(size_t position, int choice)
{
	Direction* p_direction;
	p_direction = new ExitDirection(choice);

	m_vector.insert(m_vector.begin() + position, p_direction);
}

void Schedule::insertLeft(size_t position)
{
	Direction* p_direction;
	p_direction = new LeftDirection();

	m_vector.insert(m_vector.begin() + position, p_direction);
}

void Schedule::insertRight(size_t position)
{
	Direction* p_direction;
	p_direction = new RightDirection();

	m_vector.insert(m_vector.begin() + position, p_direction);
}

void Schedule::erase(size_t position)
{
	Direction* p_direction;
	p_direction = m_vector[position];

	m_vector.erase(m_vector.begin() + position);
	delete p_direction;
}

void Schedule::printAll()
{
	accept(&PrintVisitor());
}

void Schedule::saveFile(std::string fileName) // TODO: exceptions here
{
	std::fstream file(fileName, std::ios::out);
	accept(&PrintFileVisitor(&file));
	file.close();
}

using namespace std;
using namespace std::placeholders;

void Schedule::accept(Visitor *visitor) {
	for_each(m_vector.begin(), m_vector.end(),
		bind(&Direction::accept, _1, visitor));
}