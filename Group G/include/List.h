#ifndef LIST_H
#define LIST_H

#include <Action.h>
#include <string>
#include "Inventory.h"

class List : public Action
{
    public:
        List(Inventory* inv);
        virtual ~List();

    protected:

    private:
        Inventory* inventory;
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
};

#endif // LIST_H
