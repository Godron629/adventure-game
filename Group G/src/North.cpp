#include "North.h"
#include <string>
#include <iostream>
using namespace std;

North::North()
{
    //ctor
    description = "north";
    object = "North";
}

North::~North()
{
    //dtor
}
string North::GetDescription()
{
    return description;
}
void North::GetObject()
{
    cout<<object<<endl<<endl;
}
