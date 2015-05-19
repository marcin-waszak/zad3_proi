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

void PrintFileVisitor::visit(ForwardDirection *p)
{
	*m_inputFile << "Prosto " << p->getDistance() << "m" << std::endl;
}

void PrintFileVisitor::visit(ExitDirection *p)
{
	*m_inputFile << "Zjazd nr " << p->getChoice() << std::endl;
}

void PrintFileVisitor::visit(LeftDirection *p)
{
	*m_inputFile << "W prawo" << std::endl;
}

void PrintFileVisitor::visit(RightDirection *p)
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

PrintFileVisitor::PrintFileVisitor(std::fstream *inputFile) : m_inputFile(inputFile)
{
}