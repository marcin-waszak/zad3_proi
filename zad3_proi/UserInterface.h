#ifndef USERINTERFACE_H
#define	USERINTERFACE_H	

#include "Schedule.h"

class UserInterface
{
public:
	UserInterface(Schedule *schedule);
	int getValue(std::string input, int max, int min = 0) const;
	std::string getString(std::string input) const;

	void printHead() const;
	void mainMenu();
	void addMenu();
	void insertMenu();
	void eraseMenu();
	void clearMenu();
	void printMenu() const;
	void saveMenu();
	void loadMenu();
	void exitMenu();
//	void badChoiceMenu();

private:
	Schedule *m_schedule;
	static const int MAX_DISTANCE = 1000000000;
	static const int MAX_EXIT = 16;
};

#endif