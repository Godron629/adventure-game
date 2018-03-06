#include "RubberTube.h"
#include <string>
#include <iostream>
using namespace std;
RubberTube::RubberTube()
{
    //ctor
    description = "rubber tube";
    object = "Rubber Tube";
}

RubberTube::~RubberTube()
{
    //dtor
}
string RubberTube::GetDescription()
{
    return description;
}
void RubberTube::GetObject()
{
    cout<<object;
}
