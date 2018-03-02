#include "Grab.h"
#include <string>
#include <iostream>

using namespace std;
Grab::Grab()
{
    //ctor
    description = "grab";
    action = "Grabbing ";
}

Grab::~Grab()
{
    //dtor
}
string Grab::GetDescription()
{
    return description;
}
bool Grab::PerformAction()
{
    cout<<action;
    return false;
}
