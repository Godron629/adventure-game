#include "Grab.h"
#include <string>
#include <iostream>
#include "Item.h"
#include "Inventory.h"
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
