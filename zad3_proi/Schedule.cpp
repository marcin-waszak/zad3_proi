#include "Schedule.h"

Schedule::~Schedule()
{
	clear();
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

void Schedule::clear()
{
	size_t vectorSize = m_vector.size();
	
	for(size_t i = 0; i < vectorSize; i++)
		erase(vectorSize - i - 1);
}

void Schedule::printAll()
{
	int i = 0;
	for(auto current : m_vector)
	{
		PrintVisitor p_visitor(i++);
		current->accept(&p_visitor);
	}	
}

void Schedule::saveFile(std::string fileName)
{
	try
	{
		std::ofstream file(fileName, std::ios::binary);
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		for(auto current : m_vector)
		{
			PrintFileVisitor p_visitor(&file);
			current->accept(&p_visitor);
		}
	}
	catch(std::ios_base::failure &fail)
	{
		std::cout << "Nie mozna zapisac " << fileName << std::endl
			<< fail.what() << std::endl;
	}
}

void Schedule::loadFile(std::string fileName)
{
	int temp;
	clear();

	try
	{
		std::ifstream file(fileName);
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		while(!file.eof())
		{
			file.read(reinterpret_cast<char*>(&temp), sizeof(temp));

			switch(temp)
			{
			case Direction::Type::D_FORWARD:
				file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				this->addForward(temp);
				break;

			case Direction::Type::D_EXIT:
				file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				this->addExit(temp);
				break;

			case Direction::Type::D_LEFT:
				this->addLeft();
				break;

			case Direction::Type::D_RIGHT:
				this->addRight();
				break;
			}
		}
	}
	catch(std::ios_base::failure &fail)
	{
//		clear();
		std::cout << "Blad odczytu " << fileName << std::endl
			<< fail.what() << std::endl;
	}
}

size_t Schedule::getSize()
{
	return m_vector.size();
}