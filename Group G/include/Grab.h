#ifndef GRAB_H
#define GRAB_H
#include "Item.h"
#include "Inventory.h"
#include <Action.h>
#include <string>

class Grab : public Action
{
    public:
        Grab();
        virtual ~Grab();
    protected:

    private:
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
        void PerformAction(Item*,Inventory*);
};

#endif // GRAB_H
