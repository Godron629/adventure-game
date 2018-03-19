#ifndef TESTITEM_H
#define TESTITEM_H

#include "Item.h"
#include <cppunit/extensions/HelperMacros.h>

class TestItem : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestItem);

    CPPUNIT_TEST(test_get_description);
    CPPUNIT_TEST(test_get_object);

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void test_get_description();
        void test_get_object();

    protected:
        Item* m_item;
};

#endif // TESTITEM_H
