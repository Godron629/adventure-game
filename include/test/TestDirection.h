#ifndef TESTDIRECTION_H
#define TESTDIRECTION_H

#include "Direction.h"
#include <cppunit/extensions/HelperMacros.h>

class TestDirection : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestDirection);

    CPPUNIT_TEST(test_get_description);
    CPPUNIT_TEST(test_get_cardinal);
    CPPUNIT_TEST(test_get_object);

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();

        void test_get_description();
        void test_get_object();
        void test_get_cardinal();

    protected:
        Direction* m_direction;

};

#endif // TESTDIRECTION_H
