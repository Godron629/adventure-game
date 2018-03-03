#include "West.h"
#include <string>
#include <iostream>
using namespace std;

West::West()
{
    //ctor
    description = "west";
    object = "West";
}

West::~West()
{
    //dtor
}
string West::GetDescription()
{
    return description;
}
void West::GetObject()
{
    cout<<object<<endl<<endl;
}
