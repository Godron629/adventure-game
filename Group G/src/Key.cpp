#include "Key.h"
#include <string>
#include <iostream>
using namespace std;

Key::Key()
{
    //ctor
    description = "key";
    object = "Key";
}

Key::~Key()
{
    //dtor

}
string Key::GetDescription()
{
    return description;
}
void Key::GetObject()
{
    cout<<object;
}
