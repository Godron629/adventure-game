#include "Action.h"

#include "Inventory.h"
#include "Item.h"

#include <string>
#include <iostream>

using namespace std;

string Action::GetDescription() {
    return description;
}
/**
 *\brief returns an enum of the action Type: 'Sys, Tlk, Dir, Inv'
 */
ActionType Action::GetType() {
    return type;
}

void Action::PerformAction(Item* newItem,Inventory* currentInventory, Room* currentRoom){}
void Action::PerformAction(Room* currentRoom){}
void Action::PerformAction(Inventory* currentInventory, Map* currentMap, string code){}
void Action::PerformAction(Inventory*, Map*){}
void Action::PerformAction(Direction* dir, Map* gameMap){}
void Action::PerformAction(Inventory* currentInventory, Map* currentMap, Npc* requestedNpc){}

Drop::Drop()
{
    description = "drop";
    action = "Dropping ";
    type = Inv;
}

/**
 *\brief returns bool: true if game over, else false.
 */
bool Drop::PerformAction()
{
    cout<<action;
    return false;
}
/**
 *\brief Drops item from player inventory and adds item to current room.
 *\param[out] Pointer to Item -> the item the player is trying to drop.
 *\param[out] Pointer to Inventory -> the players inventory.
 *\param[out] Pointer to Room -> the current room the player is in.
 */
void Drop::PerformAction(Item* newItem, Inventory* currentInventory, Room* currentRoom)
{
    currentInventory->Drop(newItem);
    currentRoom->addItem(newItem);
    cout<<"Dropping: "<<newItem->GetObject()<<endl<<endl;
}

Unlock::Unlock()
{
    description = "unlock";
    action = "Unlock";
    type = Sys;
}

bool Unlock::PerformAction()
{
    cout << action;
    return false;
}
/**
 *\brief Unlocks a room if the user has a key.
 *\param[out] Pointer to Inventory -> the players inventory.
 *\param[out] Pointer to Map -> the game map.
 */
void Unlock::PerformAction(Inventory* currentInventory, Map* gameMap)
{
    for(auto i: currentInventory->inventory){
        if(i->GetDescription() == "key"){
            gameMap->sendToRoom("0"); //ROOM ID HERE
            return;
        }
    }
    cout<<"You do not have a key..."<<endl<<endl;
}
Talk::Talk()
{
    description = "talk";
    action = "Talking ";
    type = Tlk;
}
/**
 *\brief returns bool: true if game over, else false.
 */
bool Talk::PerformAction()
{
    cout << action;
    return false;
}
/**
 *\brief Initiates conversation between player and NPC.
 *\param[out] Pointer to Inventory -> the players inventory.
 *\param[out] Pointer to Map -> the current game map.
 *\param[out] Pointer to Npc -> the current NPC the player desires to speak to.
 */
void Talk::PerformAction(Inventory* currentInventory, Map* currentMap, Npc* requestedNpc)
{
    string message = "";

    for(auto i: currentMap->getCurrentRoom()->getNpcs())
    {
        if(i->getName() == requestedNpc->getName())
        {
            if(i->checkForGameCompletion(currentInventory))
                message.append(i->getThingToSay(1));
            else
                message.append(i->getThingToSay(0));
        }
    }
    if(message == "")
        message.append("There's no character by that name in this room...");

    cout<<message<<endl<<endl;
}
Type::Type()
{
    description = "type";
    action = "Typing ";
    type = Sys;
}
/**
 *\brief returns bool: true if game over, else false.
 */
bool Type::PerformAction()
{
    cout << action;
    return false;
}
/**
 *\brief For entering a code into a safe.
 *\param[out] Pointer to Inventory -> the players inventory.
 *\param[out] Pointer to Map -> the current game map.
 *\param[in] String 'code' -> the code the player wants to enter.
 */
void Type::PerformAction(Inventory* currentInventory, Map* currentMap, string code)
{
    string message = "";

    //USE ID OR NAME FOR WHICHEVER ROOM THE SAFE IS ACTUALLY IN.. THIS WAS FOR TESTING
    if(currentMap->getCurrentRoom()->getId() == "2" || currentMap->getCurrentRoom()->getName() == "room1")
    {
        //WHATEVER CODE YOU WANT
        if(code == "8421")
        {
            message.append("Correct password - Welcome, Mr. Mad Scientist\nThere's a rubber tube inside... how curious, you take it.");
            currentInventory->Add(new RubberTube());
        }
        else
        {
            message.append("Incorrect password - Activating alarm system");
            currentMap->sendToRoom("0"); //ROOM ID -3 WILL BE "PIT OF AGONY"
        }
    }
    else
    {
        message.append("There's nothing to type on...");
    }
    cout<<message<<endl<<endl;
}

Crank::Crank()
{
    description = "crank";
    action = "Cranking ";
    type = Sys;
}
/**
 *\brief returns bool: true if game over, else false.
 */
bool Crank::PerformAction()
{
    cout<<action;
    return false;
}
/**
 *\brief When the player is standing on the pressure plate and needs to turn the crank.
 *\param[out] Pointer to Inventory -> the players inventory.
 *\param[out] Pointer to Map -> the current game map.
 */
void Crank::PerformAction(Inventory* currentInventory, Map* currentMap)
{
    bool hasWeight = false;
    bool hasHelmet = false;

    string message = "";
    if(currentMap->getCurrentRoom()->getId() == "2" || currentMap->getCurrentRoom()->getName() == "room1")
    {
        for(auto i: currentInventory->inventory)
            if(i->GetDescription() == "heavy weight")
                hasWeight = true;
        for(auto i: currentInventory->inventory)
            if(i->GetDescription() == "helmet")
                hasHelmet = true;

        if(hasWeight)
        {
            message.append("The pressure plate gives a little and you turn the crank.\nA gear falls from the ceiling, watch out!");
            if(hasHelmet)
            {
                message.append("\nOof! That hurt. Who throws a gear? Honestly. You pick it up in spite of your injury.");
                currentInventory->Add(new Gear());
            }
            else
            {
                message.append("\nOof! You are hit in the head with something heavy!\nYou fall into the conspicuously placed 'Pit of Doom'...");
                currentMap->sendToRoom("0");//NAME = PIT OF DOOM || ID = -3
            }
        }
        else
            message.append("The pressure plate under your feet binds slightly, but the crank won't move !\nYou wonder if you could somehow make yourself heavier...");
    }
    else
        message.append("There is nothing to crank here... ");
    cout<<message<<endl<<endl;
}

Grab::Grab()
{
    description = "grab";
    action = "Grabbing ";
    type = Inv;
}
/**
 *\brief returns bool: true if game over, else false.
 */
bool Grab::PerformAction()
{
    cout<<action;
    return false;
}
/**
 *\brief Adds Item to players inventory and removes the item from the current room.
 *\param[out] Pointer to Item -> current item the player wishes to add
 *\param[out] Pointer to Inventory -> the players inventory.
 *\param[out] Pointer to Room -> the current room.
 */
void Grab::PerformAction(Item* newItem, Inventory* currentInventory, Room* currentRoom)
{
    for(auto i: currentRoom->getItems())
    {
        if(i->GetDescription() == newItem->GetDescription())
        {
            currentInventory->Add(newItem);
            currentRoom->removeItem(newItem);
            cout<<"Grabbing: "<<newItem->GetObject()<<endl<<endl;
            return;
        }
    }
    cout<<"You can't pick up an item that does not exist.\n\n";
    return;
}

Help::Help()
{
    description = "help";
    action = "Actions: Help | Quit | List | Look | Crank | Move |\n\t | Grab | Drop | Type | Talk | Unlock";
    type = Sys;
}
/**
 *\brief returns bool: true if game over, else false.
 */
bool Help::PerformAction()
{
    cout<<action<<endl<<endl;
    return false;
}

List::List(Inventory* inv)
{
    inventory = inv;
    description = "list";
    action = "Inventory: ";
    type = Sys;
}
/**
 *\brief returns bool: true if game over, else false. Shows players inventory to Console.
 */
bool List::PerformAction()
{
    cout<<action;
    inventory->List();
    return false;
}

Look::Look()
{
    description = "look";
    action = "Looking ";
    type = Sys;
}
/**
 *\brief returns bool: true if game over, else false.
 */
bool Look::PerformAction()
{
    cout<<action;
    return false;
}
/**
 *\brief Looking around when entering a new room.
 *\param[out] Pointer to Room -> current room.
 */
void Look::PerformAction(Room* currentRoom)
{
    string toPrint = currentRoom->getDescription();
    toPrint.append("\n\nArea Contains: ");

    int numOfItems = currentRoom->getItems().size();

    if(!numOfItems) {
        toPrint.append("Nothing");
    }

    for(int i = 0; i < numOfItems; i++)
    {
        toPrint.append(currentRoom->getItems()[i]->GetObject());

        if (i != numOfItems-1)
            toPrint.append(" | ");
    }

    cout << toPrint << endl << endl;
    return;
}

Move::Move()
{
    description = "move";
    action = "Moving ";
    type = Dir;
}
/**
 *\brief moving within the map.
 *\param[out] Pointer to Direction -> direction the player wishes to move.
 *\param[out] Pointer to Map -> the current game map.
 */
void Move::PerformAction(Direction* dir, Map* gameMap)
{
    gameMap->changeCurrentRoom(dir->GetCardinal());
}
/**
 *\brief returns bool: true if game over, else false.
 */
bool Move::PerformAction()
{
    cout<<action;
    return false;
}

Quit::Quit()
{
    description = "quit";
    action = "Quitting...";
    type = Sys;
}
/**
 *\brief returns bool: true if game over, else false.
 */
bool Quit::PerformAction()
{
    cout<<action<<endl;
    return true;
}
