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
	PrintVisitor(int current);
	void visit(ForwardDirection*);
	void visit(ExitDirection*);
	void visit(LeftDirection*);
	void visit(RightDirection*);

private:
	int m_current;
};

class GetIDVisitor : public Visitor
{
public:
	GetIDVisitor(int *id);
	void visit(ForwardDirection*);
	void visit(ExitDirection*);
	void visit(LeftDirection*);
	void visit(RightDirection*);

private:
	int *m_id;
};

class PrintFileVisitor : public Visitor
{
public:
	PrintFileVisitor(std::ofstream *inputFile);
	void visit(ForwardDirection*);
	void visit(ExitDirection*);
	void visit(LeftDirection*);
	void visit(RightDirection*);

private:
	std::ofstream *m_inputFile;
};

#endif