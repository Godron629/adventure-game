#include "../include/Item.h"

#include <string>

using std::string;

string Item::GetDescription() {
    return description;
}

string Item::GetObject() {
    return object;
}

FishFood::FishFood()
{
    description = "fish food";
    object = "Fish Food";
}

Gear::Gear()
{
    description = "gear";
    object = "Gear";
}

Weight::Weight()
{
    description = "heavy weight";
    object = "Heavy Weight";
}

Helmet::Helmet()
{
    description = "helmet";
    object = "Helmet";
}

Key::Key()
{
    description = "key";
    object = "Key";
}

PileOfBolts::PileOfBolts()
{
    description = "pile of bolts";
    object = "Pile of Bolts";
}

RatPoison::RatPoison()
{
    description = "rat poison";
    object = "Rat Poison";
}

RubberTube::RubberTube()
{
    description = "rubber tube";
    object = "Rubber Tube";
}

Stick::Stick()
{
    description = "stick";
    object = "Stick";
}

Papyrus::Papyrus() {
    description = "papyrus";
    object = "Papyrus";
}

Quill::Quill() {
    description = "quill";
    object = "Quill";
}
