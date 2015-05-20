#include "UserInterface.h"
#include "Utilities.h"

UserInterface::UserInterface(Schedule *schedule) : m_schedule(schedule)
{
}

int UserInterface::getValue(std::string label, int max, int min)
{
	std::string value;
	int result;
	while(1)
	{
		std::cout << label;
		std::getline(std::cin, value);
		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if(!Utilities::isInteger(value)) continue;
		else result = atoi(value.c_str());
		if(result < min || result > max) continue;
		break;
	}
	return result;
}

std::string UserInterface::getString(std::string label)
{
	std::string output;
//	while(1)
//	{
		std::cout << label;
		std::getline(std::cin, output);
		std::cin.clear();
//		break;
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	}
	return output;
}

void UserInterface::printHead()
{
	std::cout << std::endl
		<< "------------------------------------------------\n"
		<< "Wskazowki dojazdu - Marcin Waszak" << std::endl;
}

void UserInterface::mainMenu()
{
	int choice;
	while(1)
	{
		printHead();
		std::cout << std::endl
			<< "0. Dodaj wskazowke\n"
			<< "1. Wstaw wskazowke\n"
			<< "2. Skasuj wskazowke\n"
			<< "3. Wyczysc liste wskazowek\n"
			<< "4. Wyswietl aktualne wskazowki\n"
			<< "5. Zapisz aktualne wskazowki\n"
			<< "6. Wczytaj wskazowki z pliku\n"
			<< "7. Zakoncz dzialanie programu\n";			

		choice = getValue("Dokonaj wybroru [0 - 7]: ", 7);
		switch(choice)
		{
			case 0: addMenu(); break;
			case 1: insertMenu(); break;
			case 2: eraseMenu(); break;
			case 3: clearMenu(); break;
			case 4: printMenu(); break;
			case 5: saveMenu(); break;
			case 6: loadMenu(); break;
			case 7: exitMenu(); break;
			default:/* badChoiceMenu();*/ continue;// ????
		}
	}
}

void UserInterface::addMenu()
{
	int choice;
	int distance;
	int c_exit;

	std::cout << std::endl
		<< "Dodawanie wskazowki\n"
		<< "0. Jedz prosto\n"
		<< "1. Zjazd\n"
		<< "2. W lewo\n"
		<< "3. W prawo\n"
		<< "4. Powrot\n";

	choice = getValue("Dokonaj wybroru [0 - 4]: ", 4);

	switch(choice)
	{
	case 0:
		distance = getValue("Podaj dystans [m]: ", MAX_DISTANCE);
		m_schedule->addForward(distance);
		Utilities::putSuccess("Dodano pomyslnie!");
		break;
	case 1:
		c_exit = getValue("Podaj numer zjadu: ", MAX_EXIT, 1);
		m_schedule->addExit(c_exit);
		Utilities::putSuccess("Dodano pomyslnie!");
		break;
	case 2:
		m_schedule->addLeft();
		Utilities::putSuccess("Dodano pomyslnie!");
		break;
	case 3:
		m_schedule->addRight();
		Utilities::putSuccess("Dodano pomyslnie!");
		break;
	case 4:
		return;
	default:
		Utilities::putError("Cos poszlo nie tak!");		
	}
}

void UserInterface::insertMenu()
{
	int distance;
	int choice;
	int c_exit;
	size_t place;
	size_t schedule_size;

	schedule_size = m_schedule->getSize();

	if(m_schedule->getSize() == 0)
	{
		Utilities::putWarning("Lista wskazowek nie moze byc pusta!");
		return;
	}

	std::stringstream ss_label;
	ss_label << "Wybierz miejsce na liscie wskazowek [0 - " << schedule_size - 1 << "]: ";

	std::cout << std::endl << "Wstawianie wskazowki\n";
	place = getValue(ss_label.str(), schedule_size - 1);
	std::cout
		<< "0. Jedz prosto\n"
		<< "1. Zjazd\n"
		<< "2. W lewo\n"
		<< "3. W prawo\n"
		<< "4. Powrot\n";

		choice = getValue("Dokonaj wybroru [0 - 4]: ", 4);
		if(choice == 4) return;

	switch(choice)
	{
	case 0:
		distance = getValue("Podaj dystans [m]: ", MAX_DISTANCE);
		m_schedule->insertForward(place, distance);
		Utilities::putSuccess("Wstawiono pomyslnie!");
		break;
	case 1:
		c_exit = getValue("Podaj numer zjadu: ", MAX_EXIT, 1);
		m_schedule->insertExit(place, c_exit);
		Utilities::putSuccess("Wstawiono pomyslnie!");
		break;
	case 2:
		m_schedule->insertLeft(place);
		Utilities::putSuccess("Wstawiono pomyslnie!");
		break;
	case 3:
		m_schedule->insertRight(place);
		Utilities::putSuccess("Wstawiono pomyslnie!");
		break;
	//case 4:
	//	return;
	default:
		Utilities::putError("Cos poszlo nie tak!");
	}
}

void UserInterface::eraseMenu()
{
	size_t place;
	std::cout << "Usuwanie wskazowki\n";

	if(m_schedule->getSize() == 0)
	{
		Utilities::putWarning("Lista wskazowek jest pusta!");
		return;
	}

	place = getValue("Wybierz numer wskazowki: ", m_schedule->getSize() - 1);
	m_schedule->erase(place);
	Utilities::putSuccess("Skasowano pomyslnie!");
}

void UserInterface::clearMenu()
{
	int decision;
	Utilities::putWarning("\nCzyszczenie calej listy wskazowek");
		std::cout
		<< "0. Rezygnuje\n"
		<< "1. Potwierdzam\n";

	decision = getValue("Decyzja [0 - 1]: ", 1);
	if(decision == 1)
	{
		m_schedule->clear();
		Utilities::putSuccess("Skasowano pomyslnie!");
	}
}

void UserInterface::printMenu()
{
	std::cout << "\nWyswietlanie listy\n";
	if(m_schedule->getSize() == 0)
	{
		Utilities::putWarning("< lista wskazowek jest pusta >");
		return;
	}
	if(m_schedule->detectLeft())
		Utilities::putWarning("UWAGA: Trasa zawiera lewoskret!");
	m_schedule->printAll();
}

void UserInterface::saveMenu()
{
	std::string name;
	std::cout
		<< "Zapisywanie listy wskazowek do pliku\n"
		<< "Aby anulowac wpisz pusta nazwe pliku\n";
	name = getString("Podaj nazwe pliku do zapisu: ");
	if(name.size() != 0)
		m_schedule->saveFile(name);
}

void UserInterface::loadMenu()
{
	std::string name;
	std::cout << std::endl
		<< "Wczytywanie listy wskazowek z pliku\n";
	Utilities::putWarning("\nUWAGA: Obecna lista zostanie bezpowrotnie zastapiona!");
	std::cout << "Aby anulowac wpisz pusta nazwe pliku do wczytania\n";

	name = getString("Podaj nazwe pliku do wczytania: ");
	if(name.size() != 0)
	{
		m_schedule->clear();
		m_schedule->loadFile(name);
	}
}

void UserInterface::exitMenu()
{
	int decision;
	Utilities::putWarning("\nCzyszczenie calej listy wskazowek");
	std::cout
		<< "Czy na pewno chcesz opuscic program?\n"
		<< "0. Rezygnuje\n"
		<< "1. Potwierdzam\n";

	decision = getValue("Decyzja [0 - 1]: ", 1);
	if(decision == 1)
		exit(0);
}