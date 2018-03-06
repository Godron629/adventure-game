#include "Diary.h"
#include <string>
#include <iostream>
using namespace std;
Diary::Diary()
{
    //ctor
    description = "diary";
    object = "Diary";
    entries = {"Game started!", "We hella lit bruh"};
}

Diary::~Diary()
{
    //dtor
}
string Diary::GetDescription()
{
    return description;
}
void Diary::GetObject()
{
    cout<<object;
}
void Diary::AddEntry(string entry)
{
    entries.insert(entries.end(),entry);
}
vector<string> Diary::GetEntries()
{
    return entries;
}
