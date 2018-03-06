#include "Inventory.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "Option.h"

using namespace std;
Inventory::Inventory()
{
    //ctor
    inventory = {};
}

Inventory::~Inventory()
{
    //dtor
    for(auto i: inventory)
        delete i;
}
void Inventory::Add(Item* addedItem)
{
    inventory.push_back(addedItem);
}
void Inventory::Drop(Item* droppedItem)
{
    if(find(inventory.begin(),inventory.end(),droppedItem)!= inventory.end())
        inventory.erase(remove(inventory.begin(),inventory.end(),droppedItem),inventory.end());
    else
        throw invalid_argument("Item not in your inventory!");
}
void Inventory::List()
{
    if(inventory.begin() == inventory.end())
        cout<<"*empty*";

    for(auto i: inventory)
    {
        Item* tempItem = i;
        tempItem->GetObject();
        cout<<" | ";
    }

    cout<<endl<<endl;
}
