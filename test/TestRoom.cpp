#include "TestRoom.h"
#include "Item.h"
#include "Npc.h"
#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

CPPUNIT_TEST_SUITE_REGISTRATION(TestRoom);

void TestRoom::test_get_id() {
    tNeighbours neighbours = {{"n", "z"}};;
    tNpcList npcs;
    npcs.push_back(new Scientist());

    tItemList items;
    items.push_back(new Helmet());

    string result = Room("1", "name", "description", neighbours, npcs, items).getId();
    string expectedResult = "2";
    CPPUNIT_ASSERT_EQUAL(result, expectedResult);
}

void TestRoom::test_get_name() {};
void TestRoom::test_get_neighbour_n() {};
void TestRoom::test_get_neighbour_s() {};
void TestRoom::test_get_neighbour_e() {};
void TestRoom::test_get_neighbour_w() {};
void TestRoom::test_get_neighbour_u() {};
void TestRoom::test_get_neighbour_d() {};
void TestRoom::test_get_npcs() {};
void TestRoom::test_get_items() {};
void TestRoom::test_delete_item() {};
void TestRoom::test_add_item() {};
