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
    if(index < (int)thingsToSay.size())
        return thingsToSay[index];
}

bool Npc::checkForGameCompletion(Inventory* currentInventory)
{
    for(auto i: currentInventory->inventory)
        if(i->GetDescription() == "pile of bolts")
            return true;
    return false;
}

Scientist::Scientist()
{
    name = "scientist";
    thingsToSay = {"I'm just a Mad Scientist", "AyyyLmao"};
}

Boy::Boy()
{
    name = "boy";
    thingsToSay = {"I'm just a Little Boy Duck", "hehehehe"};
}

Father::Father()
{
    name = "father";
    thingsToSay = {"Luke.... I am your father","I'm also you son"};
}
