#include "Look.h"
#include <string>
#include <iostream>
using namespace std;
Look::Look()
{
    //ctor
    description = "look";
    action = "Looking ";
    type = Dir;
}

Look::~Look()
{
    //dtor
}
string Look::GetDescription()
{
    return description;
}
ActionType Look::GetType()
{
    return type;
}
bool Look::PerformAction()
{
    cout<<action;
    return false;
}
