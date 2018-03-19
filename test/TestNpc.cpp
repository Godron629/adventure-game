#include "TestNpc.h"

#include <string>

#include <Inventory.h>
#include <Item.h>

using std::string;

CPPUNIT_TEST_SUITE_REGISTRATION(TestNpc);

void TestNpc::setUp() {
    m_npc = new Boy();
}

void TestNpc::test_get_name() {
    string result = m_npc->getName();
    string expectedResult = "boy";
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
}

void TestNpc::test_get_thing_to_say() {
    string result = m_npc->getThingToSay(1);
    string expectedResult = "Wow, thanks for looking for my father. I just saw him around here somewhere...";
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
};

void TestNpc::test_check_for_game_completion_false() {
    Inventory inv;
    Inventory* invPtr = &inv;
    bool result = m_npc->checkForGameCompletion(invPtr);
    bool expectedResult = false;
    CPPUNIT_ASSERT_EQUAL(expectedResult, result);
};

void TestNpc::test_check_for_game_completion_true() {
    Inventory inv;

    inv.Add(new RubberTube);
    inv.Add(new Gear);
    inv.Add(new Papyrus);
    inv.Add(new PileOfBolts);

    Inventory* invPtr = &inv;
    bool result = m_npc->checkForGameCompletion(invPtr);
    bool expectedResult = true;
    CPPUNIT_ASSERT_EQUAL(expectedResult, result);
};
