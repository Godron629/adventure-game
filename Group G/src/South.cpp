#include "South.h"
#include <string>
#include <iostream>
using namespace std;

South::South()
{
    //ctor
    description = "south";
    object = "South";
}

South::~South()
{
    //dtor
}
string South::GetDescription()
{
    return description;
}
void South::GetObject()
{
    cout<<object<<endl<<endl;
}
