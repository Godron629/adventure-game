#include "Move.h"
#include <string>
#include <iostream>
using namespace std;
Move::Move()
{
    description = "move";
    action = "Moving ";
    type = Dir;
    //ctor
}

Move::~Move()
{
    //dtor
}
string Move::GetDescription()
{
    return description;
}
ActionType Move::GetType()
{
    return type;
}
bool Move::PerformAction()
{
    cout<<action;
    return false;
}
