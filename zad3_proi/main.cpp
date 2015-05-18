#include "Schedule.h"

int main()
{
	PrintVisitor w;
	ForwardDirection obj(66);
	obj.accept(&w);
	return 0;
}