#include "Helmet.h"
#include <string>
#include <iostream>
using namespace std;
Helmet::Helmet()
{
    //ctor
    description = "helmet";
    object = "Helmet";
}

Helmet::~Helmet()
{
    //dtor
}
string Helmet::GetDescription()
{
    return description;
}
void Helmet::GetObject()
{
    cout<<object;
}
