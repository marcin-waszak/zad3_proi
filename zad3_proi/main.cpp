#include "Schedule.h"

int main()
{
	std::fstream output_file("plik.txt", std::ios::out);
	printFileVisitor fprint_visitor(&output_file);
	RightDirection obj;
	obj.accept(&fprint_visitor);

	output_file.close();

	return 0;
}