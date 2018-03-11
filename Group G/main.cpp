//////////////////////////////////////////////////
//////////////////////////////////////////////////
//IF YOU ADD ITEM CLASSES BE SURE TO ADD THEM IN//
//CONSOLE.H -> VECTOR<OPTION*>() THEN IT IS GOOD//
//          TO BE USED IN THE GAME              //
//////////////////////////////////////////////////
//////////////////////////////////////////////////
#include <iostream>
#include "include/Console.h"
#include "Map.h"

using namespace std;

int main()
{
    Map* gameMap = new Map();
    gameMap->generateMapFromXml("rooms.xml");

    Inventory* inventory = new Inventory();

    Console shell = Console(inventory, gameMap);

    shell.PrintArt("start.txt");

    shell.Run();

    return 0;
}
