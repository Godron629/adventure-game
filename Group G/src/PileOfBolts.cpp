#include "PileOfBolts.h"
#include <string>
#include <iostream>
using namespace std;
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
