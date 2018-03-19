#include "TestDirection.h"

#include <string>

using std::string;

CPPUNIT_TEST_SUITE_REGISTRATION(TestDirection);

void TestDirection::setUp() {
    m_direction = new North;
}

void TestDirection::test_get_description() {
    string expectedResult = "north";
    string result = m_direction->GetDescription();
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
}

void TestDirection::test_get_cardinal() {
    string expectedResult = "N";
    string result = m_direction->GetCardinal();
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
}

void TestDirection::test_get_object() {
    string expectedResult = "North";
    string result = m_direction->GetObject();
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
}
