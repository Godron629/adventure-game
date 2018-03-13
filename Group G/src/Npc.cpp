#include "Npc.h"
#include <string>
#include <vector>
#include <iostream>

#include "Inventory.h"

using namespace std;

string Npc::getName()
{
    return name;
}

string Npc::getThingToSay(int index)
{
    return thingsToSay[index];
}

bool Npc::checkForGameCompletion(Inventory* currentInventory)
{
    bool hasGear = false;
    bool hasBolts = false;
    bool hasTube = false;

    for(auto i: currentInventory->inventory)
    {
        if(i->GetDescription() == "gear") hasGear = true;
        if(i->GetDescription() == "pile of bolts") hasBolts = true;
        if(i->GetDescription() == "rubber tube") hasTube = true;
    }

    return (hasGear && hasBolts && hasTube);
}

Scientist::Scientist()
{
    name = "scientist";
    thingsToSay = {"I'm just a Mad Scientist", "You have completed the game! \nFeel free to stick around and hang out or you can type 'quit' to exit..."};
}

Boy::Boy()
{
    name = "boy";
    thingsToSay = {"I'm just a Little Boy Duck", "You have completed the game! \nFeel free to stick around and hang out or you can type 'quit' to exit..."};
}

Father::Father()
{
    name = "father";
    thingsToSay = {"Luke.... I am your father","You have completed the game! \nFeel free to stick around and hang out or you can type 'quit' to exit..."};
}
