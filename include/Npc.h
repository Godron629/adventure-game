#ifndef NPC_H
#define NPC_H
#include <string>
#include <vector>
#include "Inventory.h"

class Npc
{
    public:
        Npc(){};
        virtual ~Npc(){};
        virtual std::string getName();
        virtual std::string getThingToSay(int);
        virtual bool checkForGameCompletion(Inventory*);

    protected:
        std::string name;
        std::vector<std::string> thingsToSay;
    private:

};

class Scientist : public Npc
{
    public:
        Scientist();
};

class Boy : public Npc
{
    public:
        Boy();
};

class Father : public Npc
{
    public:
        Father();
};
#endif // NPC_H
