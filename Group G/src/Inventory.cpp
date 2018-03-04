#include "Inventory.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "Item.h"
#include "Key.h"

using namespace std;
Inventory::Inventory()
{
    //ctor
    inventory = {};
}

Inventory::~Inventory()
{
    //dtor
    delete &inventory;
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
        throw invalid_argument("Does not exist");
}
void Inventory::List()
{
    if(inventory.begin() == inventory.end())
        cout<<"*empty*";

    for(int i = 0; i < inventory.size(); i++)
    {
        Item* tempItem = inventory[i];
        tempItem->GetObject();
        cout<< " | ";
    }


    cout<<endl<<endl;
}
