#include <iostream>
#include "../include/Console.h"
#include "../include/Map.h"
#include "../include/Npc.h"

using namespace std;

int main(int a, char* v[])
{
    Map* gameMap = new Map();

    gameMap->generateMapFromXml("project/rooms.xml");

    Inventory* inventory = new Inventory();

    Console shell = Console(inventory, gameMap);

    //Move These
    shell.GameStart();

    delete inventory;
    delete gameMap;

    return 0;
}
