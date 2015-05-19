#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
#include <fstream>

class ForwardDirection;
class ExitDirection;
class LeftDirection;
class RightDirection;

class Visitor
{
public:
	virtual void visit(ForwardDirection*) = 0;
	virtual void visit(ExitDirection*) = 0;
	virtual void visit(LeftDirection*) = 0;
	virtual void visit(RightDirection*) = 0;
};

class PrintVisitor : public Visitor
{
public:
	void visit(ForwardDirection*);
	void visit(ExitDirection*);
	void visit(LeftDirection*);
	void visit(RightDirection*);

private:
	int index = 0;
};

class CheckLeftVisitor : public Visitor
{
public:
	CheckLeftVisitor(bool *flag);
	void visit(ForwardDirection*);
	void visit(ExitDirection*);
	void visit(LeftDirection*);
	void visit(RightDirection*);

private:
	bool *m_left;
};

class PrintFileVisitor : public Visitor
{
public:
	PrintFileVisitor(std::fstream *inputFile);
	void visit(ForwardDirection*);
	void visit(ExitDirection*);
	void visit(LeftDirection*);
	void visit(RightDirection*);

private:
	std::fstream *m_inputFile;
};

#endif