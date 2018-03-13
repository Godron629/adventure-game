#include "Action.h"

#include "Inventory.h"
#include "Item.h"

#include <string>
#include <iostream>

using namespace std;

string Action::GetDescription() {
    return description;
}

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

bool Drop::PerformAction()
{
    cout<<action;
    return false;
}

void Drop::PerformAction(Item* newItem, Inventory* currentInventory, Room* currentRoom)
{
    currentInventory->Drop(newItem);
    //drop item into room. AddItem() in room.
    cout<<"Dropping: "<<newItem->GetObject()<<endl<<endl;
}

Talk::Talk()
{
    description = "talk";
    action = "Talking ";
    type = Tlk;
}

bool Talk::PerformAction()
{
    cout << action;
    return false;
}

void Talk::PerformAction(Inventory* currentInventory, Map* currentMap, Npc* requestedNpc)
{
    for(auto i: currentMap->getCurrentRoom()->getNpcs())
    {
        if(i->getName() == requestedNpc->getName())
        {
            i->checkForGameCompletion(currentInventory);
            return;
        }
    }
    cout<<"There's no character by that name in this room..."<<endl<<endl;
}
Type::Type()
{
    description = "type";
    action = "Typing ";
    type = Sys;
}

bool Type::PerformAction()
{
    cout << action;
    return false;
}

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

bool Crank::PerformAction()
{
    cout<<action;
    return false;
}

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

bool Grab::PerformAction()
{
    cout<<action;
    return false;
}

void Grab::PerformAction(Item* newItem, Inventory* currentInventory, Room* currentRoom)
{
    for(auto i: currentRoom->getItems())
    {
        if(i->GetDescription() == newItem->GetDescription())
        {
            currentInventory->Add(newItem);
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
    action = "Actions: Help | Quit | List | Move | Grab | Drop | Look | Type | Crank | Talk";
    type = Sys;
}

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

bool Look::PerformAction()
{
    cout<<action;
    return false;
}

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

void Move::PerformAction(Direction* dir, Map* gameMap)
{
    gameMap->changeCurrentRoom(dir->GetCardinal());
}

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

bool Quit::PerformAction()
{
    cout<<action<<endl;
    return true;
}
