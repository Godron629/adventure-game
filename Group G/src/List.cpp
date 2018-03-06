#include "List.h"
#include "Inventory.h"
#include <string>
#include <iostream>

using namespace std;
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
