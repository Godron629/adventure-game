#include "Item.h"
#include "Option.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

Item::Item()
{
    //ctor
}

Item::~Item()
{
    //dtor
}

FishFood::FishFood()
{
    //ctor
    description = "fish food";
    object = "Fish Food";
}

FishFood::~FishFood()
{
    //dtor
}
string FishFood::GetDescription()
{
    return description;
}
string FishFood::GetObject()
{
    return object;
}

Gear::Gear()
{
    //ctor
    description = "gear";
    object = "Gear";
}

Gear::~Gear()
{
    //dtor
}
string Gear::GetDescription()
{
    return description;
}
string Gear::GetObject()
{
    return object;
}

Helmet::Helmet()
{
    //ctor
    description = "helmet";
    object = "Helmet";
}

Helmet::~Helmet()
{
    //dtor
}
string Helmet::GetDescription()
{
    return description;
}
string Helmet::GetObject()
{
    return object;
}

Key::Key()
{
    //ctor
    description = "key";
    object = "Key";
}

Key::~Key()
{
    //dtor

}
string Key::GetDescription()
{
    return description;
}
string Key::GetObject()
{
    return object;
}

PileOfBolts::PileOfBolts()
{
    //ctor
    description = "pile of bolts";
    object = "Pile of Bolts";
}

PileOfBolts::~PileOfBolts()
{
    //dtor
}
string PileOfBolts::GetDescription()
{
    return description;
}
string PileOfBolts::GetObject()
{
    return object;
}

RatPoison::RatPoison()
{
    //ctor
    description = "rat poison";
    object = "Rat Poison";
}

RatPoison::~RatPoison()
{
    //dtor
}
string RatPoison::GetDescription()
{
    return description;
}
string RatPoison::GetObject()
{
    return object;
}

RubberTube::RubberTube()
{
    //ctor
    description = "rubber tube";
    object = "Rubber Tube";
}

RubberTube::~RubberTube()
{
    //dtor
}
string RubberTube::GetDescription()
{
    return description;
}
string RubberTube::GetObject()
{
    return object;
}

Stick::Stick()
{
    //ctor
    description = "stick";
    object = "Stick";
}

Stick::~Stick()
{
    //dtor
}
string Stick::GetDescription()
{
    return description;
}
string Stick::GetObject()
{
    return object;
}



