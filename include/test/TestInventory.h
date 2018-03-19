#ifndef TESTINVENTORY_H
#define TESTINVENTORY_H

#include "Inventory.h"
#include <cppunit/extensions/HelperMacros.h>

class TestInventory : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestInventory);

    CPPUNIT_TEST(test_add_item_to_inventory);
    CPPUNIT_TEST(test_drop_item_from_inventory);

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void test_add_item_to_inventory();
        void test_drop_item_from_inventory();

    protected:
        Inventory* m_inv;
};

#endif // TESTINVENTORY_H
