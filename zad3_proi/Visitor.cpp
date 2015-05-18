#include "Visitor.h"
#include "Direction.h"

// Print on the screen visitor

void PrintVisitor::visit(ForwardDirection *p)
{
	std::cout << "Prosto " << p->getDistance() << "m" << std::endl;
}

void PrintVisitor::visit(ExitDirection *p)
{
	std::cout << "Zjazd nr " << p->getChoice() << std::endl;
}

void PrintVisitor::visit(LeftDirection *p)
{
	std::cout << "W lewo" << std::endl;
}

void PrintVisitor::visit(RightDirection *p)
{
	std::cout << "W prawo" << std::endl;
}

// Print to a file visitor

void printFileVisitor::visit(ForwardDirection *p)
{
	*m_inputFile << "Prosto " << p->getDistance() << "m" << std::endl;
}

void printFileVisitor::visit(ExitDirection *p)
{
	*m_inputFile << "Zjazd nr " << p->getChoice() << std::endl;
}

void printFileVisitor::visit(LeftDirection *p)
{
	*m_inputFile << "W prawo" << std::endl;
}

void printFileVisitor::visit(RightDirection *p)
{
	*m_inputFile << "W prawo" << std::endl;
}

CheckLeftVisitor::CheckLeftVisitor(bool *flag) : m_left(flag)
{
}

// Turn-left check visitor

void CheckLeftVisitor::visit(ForwardDirection *p)
{
	*m_left = false;
}

void CheckLeftVisitor::visit(ExitDirection *p)
{
	*m_left = false;
}

void CheckLeftVisitor::visit(LeftDirection *p)
{
	*m_left = true;
}

void CheckLeftVisitor::visit(RightDirection *p)
{
	*m_left = false;
}

printFileVisitor::printFileVisitor(std::fstream *inputFile) : m_inputFile(inputFile)
{
}