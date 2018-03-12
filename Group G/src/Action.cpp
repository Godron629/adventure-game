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
void Action::PerformAction(Direction* dir, Map* gameMap){}

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
    action = "Actions: Help | Quit | List | Move | Grab | Drop | Look";
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
