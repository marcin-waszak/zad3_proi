#include <boost/test/unit_test.hpp>
#include "Schedule.h"

BOOST_AUTO_TEST_SUITE(DriveHintsTests)

BOOST_AUTO_TEST_CASE(Schedule_getSize1)
{
	Schedule main_schedule;
	BOOST_CHECK_EQUAL(main_schedule.getSize(), 0);
}

BOOST_AUTO_TEST_CASE(Schedule_getSize2)
{
	Schedule main_schedule;
	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();
	BOOST_CHECK_EQUAL(main_schedule.getSize(), 5);
}

BOOST_AUTO_TEST_CASE(Schedule_getSize3_erase)
{
	Schedule main_schedule;
	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();

	main_schedule.erase(3);
	main_schedule.erase(3);

	BOOST_CHECK_EQUAL(main_schedule.getSize(), 3);
}

BOOST_AUTO_TEST_CASE(Schedule_getSize4_erase)
{
	Schedule main_schedule;

	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();

	main_schedule.erase(3);
	main_schedule.erase(3);
	main_schedule.erase(0);
	main_schedule.erase(1);
	main_schedule.erase(0);

	BOOST_CHECK_EQUAL(main_schedule.getSize(), 0);
}

BOOST_AUTO_TEST_CASE(Schedule_getSize5_clear)
{
	Schedule main_schedule;
	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();

	main_schedule.clear();

	BOOST_CHECK_EQUAL(main_schedule.getSize(), 0);
}

BOOST_AUTO_TEST_CASE(Schedule_LeftTest1)
{
	Schedule main_schedule;

	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();
	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();

	main_schedule.erase(2);
//	main_schedule.erase(6);

	BOOST_CHECK_EQUAL(main_schedule.detectLeft(), true);
}

BOOST_AUTO_TEST_CASE(Schedule_LeftTest2)
{
	Schedule main_schedule;

	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();
	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();

	main_schedule.erase(2);
	main_schedule.erase(6);

	BOOST_CHECK_EQUAL(main_schedule.detectLeft(), false);
}

BOOST_AUTO_TEST_CASE(Schedule_OrderTest)
{
	Schedule main_schedule;

	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();
	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();

	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_EXIT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_LEFT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_RIGHT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_EXIT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_LEFT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_RIGHT);
}

BOOST_AUTO_TEST_CASE(Schedule_OrderInsertTest)
{
	Schedule main_schedule;

	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();
	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();

	main_schedule.insertForward(2, 5672);

	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_EXIT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_LEFT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_RIGHT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_EXIT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_LEFT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_RIGHT);
}

BOOST_AUTO_TEST_CASE(Schedule_OrderEraseTest)
{
	Schedule main_schedule;

	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();
	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();

	main_schedule.erase(3);

	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_EXIT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_LEFT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_RIGHT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_EXIT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_LEFT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_RIGHT);
}

BOOST_AUTO_TEST_CASE(Schedule_OrderExportImportFile)
{
	Schedule main_schedule;

	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();
	main_schedule.addForward(1);
	main_schedule.addExit(2);
	main_schedule.addLeft();
	main_schedule.addForward(23432);
	main_schedule.addRight();

	main_schedule.saveFile("temp_test.bin");
	main_schedule.clear();
	main_schedule.loadFile("temp_test.bin");

	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_EXIT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_LEFT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_RIGHT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_EXIT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_LEFT);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_FORWARD);
	main_schedule.erase(0);
	BOOST_CHECK_EQUAL(main_schedule.getID(0), Direction::Type::D_RIGHT);
}

BOOST_AUTO_TEST_SUITE_END()