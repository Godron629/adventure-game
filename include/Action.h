#ifndef ACTION_H
#define ACTION_H
#include <string>

#include "Inventory.h"
#include "Direction.h"
#include "Map.h"
#include "Item.h"

enum ActionType {Dir, Inv, Sys, Tlk};

class Action
{
    public:
        Action() {};
        virtual ~Action() {};

        std::string GetDescription();
        ActionType GetType();

        virtual bool PerformAction()=0;
        virtual void PerformAction(Item* newItem, Inventory* currentInventory, Room* currentRoom);
        virtual void PerformAction(Room* currentRoom);
        virtual void PerformAction(Inventory*, Map*, std::string);
        virtual void PerformAction(Inventory*, Map*);
        virtual void PerformAction(Direction*, Map*);
        virtual void PerformAction(Inventory*, Map*, Npc*);

    protected:
        std::string description;
        std::string action;
        ActionType type;
};

class Drop : public Action
{
    public:
        Drop();

    private:
        bool PerformAction();
        void PerformAction(Item*,Inventory*,Room*);
};
class Unlock : public Action
{
    public:
        Unlock();
    private:
        bool PerformAction();
        void PerformAction(Inventory*, Map*);

};
class Talk : public Action
{
    public:
        Talk();
    private:
        bool PerformAction();
        void PerformAction(Inventory*, Map*, Npc*);
};

class Type : public Action
{
    public:
        Type();

    private:
        bool PerformAction();
        void PerformAction(Inventory*, Map*, std::string);
};

class Crank : public Action
{
    public:
        Crank();
    private:
        bool PerformAction();
        void PerformAction(Inventory*, Map*);

};

class Grab : public Action
{
    public:
        Grab();

    private:
        bool PerformAction();
        void PerformAction(Item*,Inventory*,Room*);
};

class Help : public Action
{
    public:
        Help();

    private:
        std::string GenerateHelpOutput();
        ActionType GetType();
        bool PerformAction();
};


class Look : public Action
{
    public:
        Look();

    private:
        bool PerformAction();
        void PerformAction(Room*);
};

class List : public Action
{
    public:
        List(Inventory* inv);

    private:
        Inventory* inventory;
        bool PerformAction();
};

class Move : public Action
{
    public:
        Move();

    private:
        bool PerformAction();
        void PerformAction(Direction*, Map*);
};

class Quit : public Action
{
    public:
        Quit();

    private:
        bool PerformAction();
        void PerformAction(Inventory*, Map*);
};

#endif // ACTION_H
