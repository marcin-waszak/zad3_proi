#include "Schedule.h"

int main()
{
	Schedule main_schedule;
	main_schedule.addForward(66);
	main_schedule.addForward(777);
	main_schedule.addExit(4);
	main_schedule.addLeft();
	main_schedule.addRight();
	main_schedule.addExit(2);
	main_schedule.addLeft();

	main_schedule.printAll();
	main_schedule.saveFile("plik2.txt");

	return 0;
}