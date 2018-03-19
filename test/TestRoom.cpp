#include "TestRoom.h"
#include "Item.h"
#include "Npc.h"
#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

CPPUNIT_TEST_SUITE_REGISTRATION(TestRoom);

void TestRoom::setUp() {
    m_name = "test_name";
    m_id = "test_id";
    m_desc = "test_desc";

    m_neighbours = {
        {"n", "1"},
        {"e", "2"},
        {"s", "3"},
        {"w", "4"},
        {"u", "5"},
        {"d", "6"}};

    m_npcs.push_back(new Scientist());

    m_items.push_back(new Helmet());

    m_room = new Room(m_id, m_name, m_desc, m_neighbours, m_npcs, m_items);
}

void TestRoom::test_get_id() {
    string expectedResult = "test_id";
    string result = m_room->getId();
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
}

void TestRoom::test_get_name() {
    string expectedResult = "test_name";
    string result = m_room->getName();
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
};

void TestRoom::test_get_npcs() {
    int expectedLength = 1;
    int npcsLength = m_room->getNpcs().size();
    CPPUNIT_ASSERT_EQUAL(npcsLength, expectedLength);
};

void TestRoom::test_get_items() {
    int expectedLength = 1;
    int itemsLength = m_room->getItems().size();
    CPPUNIT_ASSERT_EQUAL(itemsLength, expectedLength);
};

void TestRoom::test_delete_item() {
    m_room->removeItem(new Helmet);
    int expectedLength = 0;
    int itemsLength = m_room->getItems().size();
    CPPUNIT_ASSERT_EQUAL(itemsLength, expectedLength);
};

void TestRoom::test_add_item() {
    m_room->addItem(new Helmet);
    int expectedLength = 2;
    int itemsLength = m_room->getItems().size();
    CPPUNIT_ASSERT_EQUAL(itemsLength, expectedLength);
};
