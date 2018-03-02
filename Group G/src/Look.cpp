#include "Look.h"
#include <string>
#include <iostream>
using namespace std;
Look::Look()
{
    //ctor
    description = "look";
    action = "Looking ";
}

Look::~Look()
{
    //dtor
}
string Look::GetDescription()
{
    return description;
}
bool Look::PerformAction()
{
    cout<<action;
    return false;
}
