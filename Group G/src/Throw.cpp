#include "Throw.h"
#include <string>
#include <iostream>
using namespace std;
Throw::Throw()
{
    //ctor
    description = "throw";
    action = "Throwing ";
}

Throw::~Throw()
{
    //dtor
}
string Throw::GetDescription()
{
    return description;
}
bool Throw::PerformAction()
{
    cout<<action;
    return false;
}
