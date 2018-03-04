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
void Read::PerformAction(Book* book)
{
    vector<string> tempEntries = book->GetEntries();

    cout<<"\tCONTENTS:\n"<<endl;

    if(tempEntries.begin() == tempEntries.end())
        cout<<"*empty*";

    for(int i = 0; i < tempEntries.size(); i++)
    {
        string tempEntry = tempEntries[i];
        cout<<"\t"<<tempEntry<<endl;
    }

    cout <<endl;
}
