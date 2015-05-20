#include "UserInterface.h"

UserInterface::UserInterface(Schedule *schedule) : m_schedule(schedule)
{
}

int UserInterface::getValue(std::string input, int max, int min)
{
	std::string value;
	int result;
	while(1)
	{
		std::cout << input;
		std::cin >> value;
		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if(!isInteger(value)) continue;
		else result = atoi(value.c_str());
		if(result < min || result > max) continue;
		break;
	}
	return result;
}

std::string UserInterface::getString(std::string input)
{
	std::string output;
	std::cin >> output;
	std::cin.clear();
	return output;
}

bool UserInterface::isInteger(std::string input)
{
	for(auto it : input)
		if(!isdigit(it))
			return false;
	return true;
}

void UserInterface::mainMenu()
{
	int choice;
	while(1)
	{
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
//		break;
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

//	while(1)
	{
		choice = getValue("Dokonaj wybroru [0 - 4]: ", 4);

		switch(choice)
		{
		case 0:
			distance = getValue("Podaj dystans: ", MAX_DISTANCE);
			m_schedule->addForward(distance);
			break;
		case 1:
			c_exit = getValue("Podaj numer zjadu: ", MAX_EXIT, 1);
			m_schedule->addExit(c_exit);
			break;
		case 2:
			m_schedule->addLeft();
			break;
		case 3:
			m_schedule->addRight();
			break;
		case 4:
			return;
		default:
			std::cout << "Cos poszlo nie tak!" << std::endl;//err
		}
	//	break;
	}
}

void UserInterface::insertMenu()
{
	int distance;
	int choice;
	int c_exit;
	size_t place;

	std::cout << std::endl
		<< "Wstawianie wskazowki\n"
		<< "0. Jedz prosto\n"
		<< "1. Zjazd\n"
		<< "2. W lewo\n"
		<< "3. W prawo\n"
		<< "4. Powrot\n";

//	while(1)
	{
		place = getValue("Wybierz miejsce na liscie wskazowek: ", m_schedule->getSize() - 1);
		choice = getValue("Dokonaj wybroru [0 - 4]: ", 4);

		switch(choice)
		{
		case 0:
			distance = getValue("Podaj dystans: ", MAX_DISTANCE);
			m_schedule->insertForward(place, distance);
			break;
		case 1:
			c_exit = getValue("Podaj numer zjadu: ", MAX_EXIT, 1);
			m_schedule->insertExit(place, c_exit);
			break;
		case 2:
			m_schedule->insertLeft(place);
			break;
		case 3:
			m_schedule->insertRight(place);
			break;
		case 4:
			return;
		default:
			std::cout << "Cos poszlo nie tak!" << std::endl;//err
		}
//		break;
	}
}

void UserInterface::eraseMenu()
{
	size_t place;
	std::cout << "Usuwanie wskazowki\n";

	if(m_schedule->getSize() == 0)
	{
		std::cout << "Lista wskazowek jest pusta!\n";
		return;
	}

//	while(1)
	{
		place = getValue("Wybierz numer wskazowki: ", m_schedule->getSize() - 1);
		m_schedule->erase(place);
		break;
//	}
}

void UserInterface::clearMenu()
{
	int decision;
	std::cout << std::endl
		<< "Czyszczenie calej listy wskazowek\n"
		<< "0. Rezygnuje\n"
		<< "1. Potwierdzam\n";

//	while(1)
	{
		decision = getValue("Decyzja [0 - 1]: ", 1);
		if(decision == 1)
			m_schedule->clear();
		break;
//	}
}

void UserInterface::printMenu()
{
	std::cout << "Wyswietlanie listy\n";
	if(m_schedule->getSize() == 0)
	{
		std::cout << "< lista wskazowek jest pusta >" << std::endl;
		return;
	}
	m_schedule->printAll();
}

void UserInterface::saveMenu()
{
	std::string name;
	std::cout << "Zapisywanie listy wskazowek do pliku" << std::endl;
	name = getString("Podaj nazwe pliku do zapusu: ");
	m_schedule->saveFile(name);
}

void UserInterface::loadMenu()
{
	std::string name;
	std::cout << std::endl
		<< "Wczytywanie listy wskazowek z pliku\n"
		<< "UWAGA: Obecna lista zostanie bezpowrotnie zastapiona!\n"
		<< "Aby anulowac wpisz pusta nazwe pliku do wczytania\n";

	name = getString("Podaj nazwe pliku do wczytania: ");
	m_schedule->loadFile(name);
}

void UserInterface::exitMenu()
{
	int decision;
	std::cout << std::endl
		<< "Opuszczanie programu\n"
		<< "Czy napewno chcesz opuscic program?"
		<< "0. Rezygnuje\n"
		<< "1. Potwierdzam\n";

//	while(1)
	{
		decision = getValue("Decyzja [0 - 1]: ", 1);
		if(decision == 1)
			exit(0);
//		break;
	}	
}

//void UserInterface::putError(std::string error)
//{
//#ifdef _WIN32
//	std::cout << error << std::endl;
//#elif __linux__
//	// ANSI escape code for red color only on Linux
//	std::cout << "\x1b[31m" << error << "\x1b[0m" << std::endl;
//#endif
//}