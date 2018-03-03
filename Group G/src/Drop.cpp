#include "Drop.h"
#include <string>
#include <iostream>

using namespace std;
Drop::Drop()
{
    //ctor
    description = "drop";
    action = "Dropping ";
    type = Inv;
}

Drop::~Drop()
{
    //dtor
}
string Drop::GetDescription()
{
    return description;
}
ActionType Drop::GetType()
{
    return type;
}
bool Drop::PerformAction()
{
    cout<<action;
    return false;
}
