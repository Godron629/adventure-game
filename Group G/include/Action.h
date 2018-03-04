#ifndef ACTION_H
#define ACTION_H
#include <string>
#include "Inventory.h"
#include "Item.h"
enum ActionType {Dir, Inv, Sys};
class Action
{
    public:
        Action();
        virtual ~Action();
        std::string description;
        std::string action;
        ActionType type;

        virtual std::string GetDescription()=0;
        virtual ActionType GetType()=0;
        virtual bool PerformAction()=0;
        virtual void PerformAction(Item*, Inventory*);

    protected:

    private:

};

#endif // ACTION_H
