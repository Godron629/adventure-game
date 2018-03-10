#ifndef ACTION_H
#define ACTION_H
#include <string>

#include "Inventory.h"
#include "Direction.h"
#include "Map.h"
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
        virtual void PerformAction(Direction*, Map*);

    protected:

    private:

};

class Drop : public Action
{
    public:
        Drop();
        virtual ~Drop();

    protected:

    private:
        ActionType GetType();
        std::string GetDescription();
        bool PerformAction();
        void PerformAction(Item*,Inventory*);
};

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

class Help : public Action
{
    public:
        Help();
        virtual ~Help();

    protected:

    private:
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
};


class Look : public Action
{
    public:
        Look();
        virtual ~Look();

    protected:

    private:
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
};

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

class Move : public Action
{
    public:
        Move();
        virtual ~Move();

    protected:

    private:
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
        void PerformAction(Direction*, Map*);
};

class Quit : public Action
{
    public:
        Quit();
        virtual ~Quit();

    protected:

    private:
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
};

class Read : public Action
{
    public:
        Read();
        virtual ~Read();

    protected:

    private:
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
};

#endif // ACTION_H
