#include "Help.h"
#include <string>
#include <iostream>
using namespace std;
Help::Help()
{
    //ctor
    description = "help";
    action = "Actions: Help | Quit | List | Move | Grab | Read | Drop | Look";
    type = Sys;
}

Help::~Help()
{
    //dtor
}
string Help::GetDescription()
{
    return description;
}
ActionType Help::GetType()
{
    return type;
}
bool Help::PerformAction()
{
    cout<<action<<endl<<endl;
    return false;
}
