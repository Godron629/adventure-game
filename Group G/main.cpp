#include <iostream>
#include "include/Console.h"
#include <thread>

using namespace std;
void GameThreadFunc(Console shell);

int main()
{
    Console shell = Console();

    thread gameThread = thread(GameThreadFunc,shell);

    gameThread.join();

    return 0;
}

void GameThreadFunc(Console shell)
{
    shell.Run();
}
