#include "Move.h"
#include <string>
#include <iostream>
using namespace std;
Move::Move()
{
    description = "move";
    action = "Moving ";
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
bool Move::PerformAction()
{
    cout<<action;
    return false;
}
