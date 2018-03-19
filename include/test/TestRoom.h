#ifndef TESTROOM_H
#define TESTROOM_H


#include "Room.h"
#include <cppunit/extensions/HelperMacros.h>


class TestRoom : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestRoom);

    CPPUNIT_TEST(test_get_id);
    CPPUNIT_TEST(test_get_name);
    CPPUNIT_TEST(test_get_neighbour_n);
    CPPUNIT_TEST(test_get_neighbour_s);
    CPPUNIT_TEST(test_get_neighbour_w);
    CPPUNIT_TEST(test_get_neighbour_e);
    CPPUNIT_TEST(test_get_neighbour_u);
    CPPUNIT_TEST(test_get_neighbour_d);
    CPPUNIT_TEST(test_get_items);
    CPPUNIT_TEST(test_get_npcs);
    CPPUNIT_TEST(test_add_item);
    CPPUNIT_TEST(test_delete_item);

    CPPUNIT_TEST_SUITE_END();

    public:

        void test_get_id();
        void test_get_name();
        void test_get_neighbour_n();
        void test_get_neighbour_s();
        void test_get_neighbour_e();
        void test_get_neighbour_w();
        void test_get_neighbour_u();
        void test_get_neighbour_d();
        void test_get_npcs();
        void test_get_items();
        void test_delete_item();
        void test_add_item();

};

#endif // TESTROOM_H
