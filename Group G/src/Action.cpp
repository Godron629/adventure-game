#include "Action.h"
#include <iostream>
#include <string>
#include "Inventory.h"
#include "Item.h"
#include "Console.h"

using namespace std;
Action::Action()
{
    //ctor

}

Action::~Action()
{
    //dtor
}

void Action::PerformAction(Item* newItem,Inventory* currentInventory, Room* currentRoom){}
void Action::PerformAction(Room* currentRoom){}
void Action::PerformAction(Direction* dir, Map* gameMap){}
Drop::Drop()
{
    //ctor
    description = "drop";
    action = "Dropping ";
    type = Inv;
}

Drop::~Drop()
{
    //dtor
}
string Drop::GetDescription()
{
    return description;
}
ActionType Drop::GetType()
{
    return type;
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

using namespace std;
Grab::Grab()
{
    //ctor
    description = "grab";
    action = "Grabbing ";
    type = Inv;
}

Grab::~Grab()
{
    //dtor
}
string Grab::GetDescription()
{
    return description;
}
ActionType Grab::GetType()
{
    return type;
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
    cout<<"Sorry that item does not exist in this room !"<<endl<<endl;
    return;
}

Help::Help()
{
    //ctor
    description = "help";
    action = "Actions: Help | Quit | List | Move | Grab | Read | Drop | Look";
    type = Sys;
}

Help::~Help()
{
    //dtor
}
string Help::GetDescription()
{
    return description;
}
ActionType Help::GetType()
{
    return type;
}
bool Help::PerformAction()
{
    cout<<action<<endl<<endl;
    return false;
}

List::List(Inventory* inv)
{
    //ctor
    inventory = inv;
    description = "list";
    action = "Inventory: ";
    type = Sys;
}

List::~List()
{
    //dtor
}
string List::GetDescription()
{
    return description;
}
ActionType List::GetType()
{
    return type;
}
bool List::PerformAction()
{
    cout<<action;
    inventory->List();
    return false;
}

Look::Look()
{
    //ctor
    description = "look";
    action = "Looking ";
    type = Sys;
}

Look::~Look()
{
    //dtor
}
string Look::GetDescription()
{
    return description;
}
ActionType Look::GetType()
{
    return type;
}
bool Look::PerformAction()
{
    cout<<action;
    return false;
}
void Look::PerformAction(Room* currentRoom)
{
    string toPrint = "Room Contains: ";

    int numOfItems = currentRoom->getItems().size();

    if(numOfItems == 0)
        toPrint.append("*empty*");


    for(int i = 0; i < numOfItems; i++)
    {
        toPrint.append(currentRoom->getItems()[i]->GetObject());

        if (i != numOfItems-1)
            toPrint.append(" | ");
    }
    cout << toPrint << endl << endl;
}

Move::Move()
{
    description = "move";
    action = "Moving ";
    type = Dir;
    //ctor
}

Move::~Move()
{
    //dtor
}
string Move::GetDescription()
{
    return description;
}
ActionType Move::GetType()
{
    return type;
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
    //ctor
    description = "quit";
    action = "Quitting...";
    type = Sys;
}

Quit::~Quit()
{
    //dtor
}
string Quit::GetDescription()
{
    return description;
}
ActionType Quit::GetType()
{
    return type;
}
bool Quit::PerformAction()
{
    cout<<action<<endl;
    return true;
}

Read::Read()
{
    //ctor
    description = "read";
    action = "Reading ";
    type = Inv;
}

Read::~Read()
{
    //dtor
}
string Read::GetDescription()
{
    return description;
}
ActionType Read::GetType()
{
    return type;
}
bool Read::PerformAction()
{
    cout<<action;
    return false;
}

