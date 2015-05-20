#include "Visitor.h"
#include "Direction.h"

// Print on the screen visitor

PrintVisitor::PrintVisitor(int current) : m_current(current)
{
}

void PrintVisitor::visit(ForwardDirection *p)
{
	std::cout << m_current << ". Prosto " << p->getDistance() << " m" << std::endl;
}

void PrintVisitor::visit(ExitDirection *p)
{
	std::cout << m_current << ". Zjazd nr " << p->getChoice() << std::endl;
}

void PrintVisitor::visit(LeftDirection *p)
{
	std::cout << m_current << ". W lewo" << std::endl;
}

void PrintVisitor::visit(RightDirection *p)
{
	std::cout << m_current << ". W prawo" << std::endl;
}

// Print to a file visitor

void PrintFileVisitor::visit(ForwardDirection *p)
{
	int direction = Direction::Type::D_FORWARD;
	int distance = p->getDistance();
	m_inputFile->write(reinterpret_cast<char*>(&direction), sizeof(int));
	m_inputFile->write(reinterpret_cast<char*>(&distance), sizeof(int));
}

void PrintFileVisitor::visit(ExitDirection *p)
{
	int direction = Direction::Type::D_EXIT;
	int choice = p->getChoice();
	m_inputFile->write(reinterpret_cast<char*>(&direction), sizeof(int));
	m_inputFile->write(reinterpret_cast<char*>(&choice), sizeof(int));
}

void PrintFileVisitor::visit(LeftDirection *p)
{
	int direction = Direction::Type::D_LEFT;
	m_inputFile->write(reinterpret_cast<char*>(&direction), sizeof(int));
}

void PrintFileVisitor::visit(RightDirection *p)
{
	int direction = Direction::Type::D_RIGHT;
	m_inputFile->write(reinterpret_cast<char*>(&direction), sizeof(int));
}

CheckLeftVisitor::CheckLeftVisitor(bool *flag) : m_left(flag)
{
	*m_left = false;
}

// Turn-left check visitor

void CheckLeftVisitor::visit(ForwardDirection *p)
{	
}

void CheckLeftVisitor::visit(ExitDirection *p)
{
}

void CheckLeftVisitor::visit(LeftDirection *p)
{
	*m_left = true;
}

void CheckLeftVisitor::visit(RightDirection *p)
{
}

PrintFileVisitor::PrintFileVisitor(std::ofstream *inputFile) : m_inputFile(inputFile)
{
}