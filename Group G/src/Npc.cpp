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
/**
 *\brief Returns the line the NPC will say.
 *\param[in] Int index -> which line the NPC should say.
 */
string Npc::getThingToSay(int index)
{
    return thingsToSay[index];
}

/**
 *\brief Returns a bool to check for game completion.
 *\param[out] Pointer to Inventory -> the players inventory.
 */
bool Npc::checkForGameCompletion(Inventory* currentInventory)
{
    bool hasGear = false;
    bool hasBolts = false;
    bool hasTube = false;
    bool hasPapyrus = false;

    for(auto i: currentInventory->inventory)
    {
        if(i->GetDescription() == "gear") hasGear = true;
        if(i->GetDescription() == "pile of bolts") hasBolts = true;
        if(i->GetDescription() == "rubber tube") hasTube = true;
        if(i->GetDescription() == "papyrus") hasPapyrus = true;
    }

    return (hasGear && hasBolts && hasTube && hasPapyrus);
}

Scientist::Scientist()
{
    name = "scientist";
    thingsToSay = {
        "Arghhh! Mom! Can't you read the sign??? It say- Oh, who are you?"
        "\nI suppose you're reconnaissance for that man...thing there. Look, this"
        "\nhere machine is my 'object polymorphizer-9001'. It makes things act like"
        "\nother things, but...well it went a step further and made that guy into a duck."
        "\nI ain't lookin' for no trouble, mister. I'd gladly return him to his be-fore form,"
        "\nbut ol' bessy - that's what I call this here machine see, blew up! Sent parts flyin'"
        "\nfrom here to the south side of 'ye olde Mississippi'. I need those parts back to"
        "\nreverse this here bung-job."
        "\n\nI need: "
        "\n- Rubber Tube"
        "\n- Pile of Bolts"
        "\n- Gear"
        "\n- Papyrus\n\n"
        "You find all them there parts, you got yourself a man. Deal? Now get outta here!",
        "Well look-ey here, thank ya kindly for finding all of that there stuff. But...I hate to"
        "\nput your through all that all them trials for nothing...but, the effect wore off."
        "\nIt turns out my machine was badly designed, and what started out as great polymorphism"
        "\ndevolved into madness! I think I'm gonna scrap this project, maybe go learn about some"
        "\nmachine-development strategies and patterns at 'ye olde university'."
        "\nFeel free to keep the stuff...it might come in...handy...I guess..."};
}

Boy::Boy()
{
    name = "boy";
    thingsToSay = {
        "Hi there! Can you help me? \n\nWe got lost, so my father went to go ask that manor directions. \n\nProblem is, well, that was six hours ago...\n\nCan you help a poor lad out?",
        "Wow, thanks for looking for my father. I just saw him around here somewhere..."};
}

Father::Father()
{
    name = "father";
    thingsToSay = {"...quack...Quack! QUACK!\n\nYou back away slowly...","Hey! *quack* who are you?"};
}
