#include "Visitor.h"
#include "Direction.h"

// Print on the screen visitor

void PrintVisitor::visit(ForwardDirection *p)
{
	std::cout << index++ << ". Prosto " << p->getDistance() << " m" << std::endl;
}

void PrintVisitor::visit(ExitDirection *p)
{
	std::cout << index++ << ". Zjazd nr " << p->getChoice() << std::endl;
}

void PrintVisitor::visit(LeftDirection *p)
{
	std::cout << index++ << ". W lewo" << std::endl;
}

void PrintVisitor::visit(RightDirection *p)
{
	std::cout << index++ << ". W prawo" << std::endl;
}

// Print to a file visitor

void PrintFileVisitor::visit(ForwardDirection *p)
{
	*m_inputFile << "Prosto " << p->getDistance() << " m" << std::endl;
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

PrintFileVisitor::PrintFileVisitor(std::fstream *inputFile) : m_inputFile(inputFile)
{
}