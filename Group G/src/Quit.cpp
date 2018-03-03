#include "Quit.h"
#include <string>
#include <iostream>
#include "Console.h"

using namespace std;
Quit::Quit()
{
    //ctor
    description = "quit";
    action = "Quitting...";
    type = Sys;
}

Quit::~Quit()
{
    //dtor
}
string Quit::GetDescription()
{
    return description;
}
ActionType Quit::GetType()
{
    return type;
}
bool Quit::PerformAction()
{
    cout<<action<<endl;
    return true;
}
