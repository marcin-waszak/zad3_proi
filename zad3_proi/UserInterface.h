#ifndef USERINTERFACE_H
#define	USERINTERFACE_H	

#include "Schedule.h"

class UserInterface
{
public:
	UserInterface(Schedule *schedule);
	int getValue(std::string input, int max, int min = 0);
	std::string getString(std::string input);
	bool isInteger(std::string input);

	void mainMenu();
	void addMenu();
	void insertMenu();
	void eraseMenu();
	void clearMenu();
	void printMenu();
	void saveMenu();
	void loadMenu();
	void exitMenu();
	void badChoiceMenu();
//	void putError(std::string error);

private:
	Schedule *m_schedule;
//	static const int MAX_CHOICE = 10;
//	static const int ERR_CHOICE = 0xFF;
	static const int MAX_DISTANCE = 1000000000;
	static const int MAX_EXIT = 16;


};

#endif