#ifndef VISITOR_H
#define	VISITOR_H

#include "Direction.h"

class Visitor
{
public:
	virtual void visit(class ForwardDirection*) = 0;
	virtual void visit(class ExitDirection*) = 0;
	virtual void visit(class LeftDirection*) = 0;
	virtual void visit(class RightDirection*) = 0;
};

class PrintVisitor: public Visitor
{
public:
	void visit(ForwardDirection*);
	void visit(ExitDirection*);
	void visit(LeftDirection*);
	void visit(RightDirection*);
};

#endif