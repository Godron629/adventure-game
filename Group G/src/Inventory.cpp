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
    int numOfItems = inventory.size();
    if(numOfItems == 0)
        cout<<"*empty*";

    for(int i = 0; i < numOfItems; i++)
    {
        Item* tempItem = inventory[i];
        tempItem->GetObject();

        if(i != numOfItems-1)
            cout<<" | ";
    }

    cout<<endl<<endl;
}
