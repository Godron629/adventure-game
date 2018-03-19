#include "TestItem.h"

#include <string>

using std::string;

CPPUNIT_TEST_SUITE_REGISTRATION(TestItem);

void TestItem::setUp() {
    m_item = new Helmet;
}

void TestItem::test_get_description() {
    string result = m_item->GetDescription();
    string expectedResult = "helmet";
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
}

void TestItem::test_get_object() {
    string result = m_item->GetObject();
    string expectedResult = "Helmet";
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
}
