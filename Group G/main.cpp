//////////////////////////////////////////////////
//////////////////////////////////////////////////
//IF YOU ADD ITEM CLASSES BE SURE TO ADD THEM IN//
//CONSOLE.H -> VECTOR<OPTION*>() THEN IT IS GOOD//
//          TO BE USED IN THE GAME              //
//////////////////////////////////////////////////
//////////////////////////////////////////////////
#include <iostream>
#include "include/Console.h"

using namespace std;

int main()
{
    Inventory* inventory = new Inventory();

    Console shell = Console(inventory);

    shell.Run();

    return 0;
}
