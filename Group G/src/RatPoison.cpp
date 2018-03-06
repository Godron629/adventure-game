#include "RatPoison.h"
#include <string>
#include <iostream>
using namespace std;
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
