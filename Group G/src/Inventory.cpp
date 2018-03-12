#include "Inventory.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "Option.h"

using namespace std;
Inventory::Inventory()
{
    inventory = {};
}

Inventory::~Inventory()
{
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

    string toPrint = "";

    if(numOfItems == 0)
        toPrint.append("*empty*");

    for(int i = 0; i < numOfItems; i++)
    {
        toPrint.append(inventory[i]->GetObject());

        if (i != numOfItems-1)
            toPrint.append(" | ");
    }
    cout << toPrint << endl << endl;
}
