#include "Visitor.h"

void PrintVisitor::visit(ForwardDirection *p)
{
	p->print();
}

void PrintVisitor::visit(ExitDirection *p)
{
	p->print();
}

void PrintVisitor::visit(LeftDirection *p)
{
	p->print();
}

void PrintVisitor::visit(RightDirection *p)
{
	p->print();
}