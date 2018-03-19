#include "TestInventory.h"
#include "Item.h"

#include <string>

using std::string;

CPPUNIT_TEST_SUITE_REGISTRATION(TestInventory);

void TestInventory::setUp() {
    m_inv = new Inventory;
}

void TestInventory::test_add_item_to_inventory() {
    m_inv->Add(new Helmet());
    int expectedSize = 1;
    int result = m_inv->inventory.size();
    CPPUNIT_ASSERT_EQUAL(expectedSize, result);
}

void TestInventory::test_drop_item_from_inventory() {
    m_inv->Add(new Helmet());
    m_inv->Drop(new Helmet());
    int expectedSize = 0;
    int result = m_inv->inventory.size();
    CPPUNIT_ASSERT_EQUAL(expectedSize, result);
};


