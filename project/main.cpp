#include <iostream>
#include "..\include\Console.h"
#include "..\include\Map.h"
#include "..\include\Npc.h"

using namespace std;

int main()
{
    Map* gameMap = new Map();
    gameMap->generateMapFromXml("rooms.xml");

    Inventory* inventory = new Inventory();

    Console shell = Console(inventory, gameMap);

    //Move These
    shell.GameStart();

    return 0;
}
