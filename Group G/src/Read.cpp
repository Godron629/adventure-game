#include "Read.h"
#include <string>
#include <iostream>
using namespace std;
Read::Read()
{
    //ctor
    description = "read";
    action = "Reading ";
    type = Inv;
}

Read::~Read()
{
    //dtor
}
string Read::GetDescription()
{
    return description;
}
ActionType Read::GetType()
{
    return type;
}
bool Read::PerformAction()
{
    cout<<action;
    return false;
}
