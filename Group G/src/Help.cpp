#include "Help.h"
#include <string>
#include <iostream>
using namespace std;
Help::Help()
{
    //ctor
    description = "help";
    action = "Actions: Help | Quit | Move | Grab | Read | Throw | Look";
}

Help::~Help()
{
    //dtor
}
string Help::GetDescription()
{
    return description;
}
bool Help::PerformAction()
{
    cout<<action<<endl<<endl;
    return false;
}
