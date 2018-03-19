#ifndef TESTNPC_H
#define TESTNPC_H

#include "Npc.h"
#include <cppunit/extensions/HelperMacros.h>

class TestNpc : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestNpc);

    CPPUNIT_TEST(test_get_name);
    CPPUNIT_TEST(test_get_thing_to_say);
    CPPUNIT_TEST(test_check_for_game_completion_false);
    CPPUNIT_TEST(test_check_for_game_completion_true);

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();

        void test_get_name();
        void test_get_thing_to_say();
        void test_check_for_game_completion_false();
        void test_check_for_game_completion_true();


    protected:
        Npc* m_npc;

};
#endif // TESTNPC_H
