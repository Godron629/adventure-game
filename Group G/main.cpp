//////////////////////////////////////////////////
//////////////////////////////////////////////////
//IF YOU ADD ITEM CLASSES BE SURE TO ADD THEM IN//
//CONSOLE.H -> VECTOR<OPTION*>() THEN IT IS GOOD//
//          TO BE USED IN THE GAME              //
//////////////////////////////////////////////////
//////////////////////////////////////////////////
#include <iostream>
#include "include/Console.h"
#include <thread>

using namespace std;
void GameThreadFunc(Console shell);

int main()
{
    Inventory* inventory = new Inventory();

    Console shell = Console(inventory);

    thread gameThread = thread(GameThreadFunc,shell);

    gameThread.join();

    return 0;
}

void GameThreadFunc(Console shell)
{
    shell.Run();
}
