#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <string>
#include <vector>

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();
        std::vector<Item*> inventory;
        void Add(Item*);
        void Drop(Item*);
        void List();
    protected:

    private:
};

#endif // INVENTORY_H
