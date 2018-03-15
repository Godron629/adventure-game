#ifndef ITEM_H
#define ITEM_H

#include "..\include\Option.h"
#include <string>
#include <vector>

class Item : public Option
{
    public:
        Item() {};
        virtual ~Item() {};
        std::string GetDescription();
        std::string GetObject();
    protected:
        std::string description;
        std::string object;
};

class FishFood : public Item
{
    public:
        FishFood();
};

class Gear : public Item
{
    public:
        Gear();
};
class Weight : public Item
{
    public:
        Weight();
};
class Helmet : public Item
{
    public:
        Helmet();
};

class Key : public Item
{
    public:
        Key();
};

class PileOfBolts : public Item
{
    public:
        PileOfBolts();
};


class RatPoison : public Item
{
    public:
        RatPoison();
};


class RubberTube : public Item
{
    public:
        RubberTube();
};


class Stick : public Item
{
    public:
        Stick();
};

class Papyrus : public Item
{
    public:
        Papyrus();
};

class Quill : public Item
{
    public:
        Quill();
};
#endif // ITEM_H

