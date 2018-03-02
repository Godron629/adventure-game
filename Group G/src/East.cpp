#include "East.h"
#include <string>
#include <iostream>
using namespace std;
East::East()
{
    //ctor
    description = "east";
    object = "East";
}

East::~East()
{
    //dtor
}
string East::GetDescription()
{
    return description;
}
void East::GetObject()
{
    cout<<object<<endl<<endl;
}
