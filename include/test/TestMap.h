#ifndef TESTMAP_H
#define TESTMAP_H

#include "Map.h"
#include <cppunit/extensions/HelperMacros.h>

class TestMap : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestMap);

    CPPUNIT_TEST(test_generate_map);
    CPPUNIT_TEST(test_change_current_room);
    CPPUNIT_TEST(test_send_to_room);
    CPPUNIT_TEST(test_get_all_rooms);

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void test_generate_map();
        void test_change_current_room();
        void test_send_to_room();
        void test_get_all_rooms();

    protected:
        Map* m_map;
};

#endif // TESTMAP_H
