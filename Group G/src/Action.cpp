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

void Action::PerformAction(Item* newItem,Inventory* currentInventory){}
void Action::PerformAction(Book* book){}

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
void Drop::PerformAction(Item* newItem, Inventory* currentInventory)
{
    currentInventory->Drop(newItem);
    cout<<"Dropping: ";
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
void Grab::PerformAction(Item* newItem, Inventory* currentInventory)
{
    currentInventory->Add(newItem);
    cout<<"Grabbing: ";
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
    type = Dir;
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
void Read::PerformAction(Book* book)
{
    vector<string> tempEntries = book->GetEntries();

    cout<<"\tCONTENTS:\n"<<endl;

    if(tempEntries.begin() == tempEntries.end())
        cout<<"*empty*";


    for(auto i: tempEntries)
    {
        string tempEnty = i;
        cout<<"\t"<<tempEnty<<endl;
    }

    cout <<endl;
}


