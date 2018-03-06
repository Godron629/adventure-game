#include "FishFood.h"
#include <string>
#include <iostream>
using namespace std;
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
