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

Book::Book()
{
    //ctor
}

Book::~Book()
{
    //dtor
}

Diary::Diary()
{
    //ctor
    description = "diary";
    object = "Diary";
    entries = {"Game started!", "We hella lit bruh"};
}

Diary::~Diary()
{
    //dtor
}
string Diary::GetDescription()
{
    return description;
}
void Diary::GetObject()
{
    cout<<object;
}
void Diary::AddEntry(string entry)
{
    entries.insert(entries.end(),entry);
}
vector<string> Diary::GetEntries()
{
    return entries;
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
void FishFood::GetObject()
{
    cout<<object;
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
void Gear::GetObject()
{
    cout<<object;
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
void Helmet::GetObject()
{
    cout<<object;
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
void Key::GetObject()
{
    cout<<object;
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
void PileOfBolts::GetObject()
{
    cout<<object;
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
void RatPoison::GetObject()
{
    cout<<object;
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
void RubberTube::GetObject()
{
    cout<<object;
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
void Stick::GetObject()
{
    cout<<object;
}



