#include "Gear.h"
#include <string>
#include <iostream>
using namespace std;
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
