#include "Read.h"
#include <string>
#include <iostream>
using namespace std;
Read::Read()
{
    //ctor
    description = "read";
    action = "Reading ";
}

Read::~Read()
{
    //dtor
}
string Read::GetDescription()
{
    return description;
}
bool Read::PerformAction()
{
    cout<<action;
    return false;
}
