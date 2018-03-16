#include "..\include\Inventory.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "..\include\Option.h"

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
/**
 *\brief Adds item into player inventory.
 *\param[out] Pointer to Item -> item the user wishes to add.
 */
void Inventory::Add(Item* addedItem)
{
    inventory.push_back(addedItem);
}
/**
 *\brief Drops item from user inventory.
 *\param[out] Pointer to Item -> item the user wishes to drop.
 *\throw Throws invalid argument exception if the inventory does not contain that item.
 */
void Inventory::Drop(Item* droppedItem)
{
    for(int i = 0; i < (int)inventory.size(); i++)
    {
        if(inventory[i]->GetDescription() == droppedItem->GetDescription())
        {
            inventory.erase(inventory.begin()+i);
            return;
        }
    }
    throw invalid_argument("Item not in your inventory!");
}
/**
 *\brief Formats and writes the users inventory to the console.
 */
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
