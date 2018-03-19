#include "TestMap.h"
#include "Room.h"

#include <string>

using std::string;

CPPUNIT_TEST_SUITE_REGISTRATION(TestMap);

void TestMap::setUp() {
    m_map = new Map();
}

void TestMap::test_generate_map() {
    CPPUNIT_ASSERT_NO_THROW(m_map->generateMapFromXml("project/test_rooms.xml"));
}

void TestMap::test_change_current_room() {
    string expectedBegin = "test1";
    string expectedEnd = "test2";

    m_map->generateMapFromXml("project/test_rooms.xml");
    string beginName = m_map->getCurrentRoom()->getName();
    m_map->changeCurrentRoom("N");
    string endName = m_map->getCurrentRoom()->getName();

    CPPUNIT_ASSERT_EQUAL(true, (expectedBegin == beginName));
    CPPUNIT_ASSERT_EQUAL(true, (expectedEnd == endName));
};

void TestMap::test_send_to_room() {
    string expectedBegin = "test1";
    string expectedEnd = "test2";

    m_map->generateMapFromXml("project/test_rooms.xml");
    string beginName = m_map->getCurrentRoom()->getName();
    m_map->sendToRoom("1");
    string endName = m_map->getCurrentRoom()->getName();

    CPPUNIT_ASSERT_EQUAL(true, (expectedBegin == beginName));
    CPPUNIT_ASSERT_EQUAL(true, (expectedEnd == endName));
};

void TestMap::test_get_all_rooms() {
    int expectedResult = 2;
    m_map->generateMapFromXml("project/test_rooms.xml");
    int result = m_map->getAllRooms().size();
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
};


