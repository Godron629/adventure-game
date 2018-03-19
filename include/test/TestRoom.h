#ifndef TESTROOM_H
#define TESTROOM_H

#include "Room.h"
#include <cppunit/extensions/HelperMacros.h>
#include <string>


class TestRoom : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestRoom);

    CPPUNIT_TEST(test_get_id);
    CPPUNIT_TEST(test_get_name);
    CPPUNIT_TEST(test_get_items);
    CPPUNIT_TEST(test_get_npcs);
    CPPUNIT_TEST(test_add_item);
    CPPUNIT_TEST(test_delete_item);

    CPPUNIT_TEST_SUITE_END();

    public:

        void setUp();

        void test_get_id();
        void test_get_name();
        void test_get_npcs();
        void test_get_items();
        void test_delete_item();
        void test_add_item();

    protected:
        Room* m_room;
        std::string m_id;
        std::string m_name;
        std::string m_desc;
        tNeighbours m_neighbours;
        tItemList m_items;
        tNpcList m_npcs;
};

#endif // TESTROOM_H
