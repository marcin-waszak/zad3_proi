#include "UserInterface.h"

int main()
{
	Schedule main_schedule;
	UserInterface main_interface(&main_schedule);
	main_interface.mainMenu();

	return 0;
}