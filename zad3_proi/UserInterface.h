#include "Schedule.h"

class UserInterface
{
public:
	int getChoice();

private:
	static const int maxChoice = 5;
	static const int E_BADCHOICE = -1;
};