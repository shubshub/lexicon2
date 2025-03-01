#include "entity.h"
#include <string>
#include <iostream>
using namespace std;

Entity::Entity(string _name, string _title)  {
    name = _name;
    title = _title;
}

bool Entity::DescribeEntity()  {
    cout << "\n";
    cout << "I am a " << title << " sitting over by the " <<  "\n";
    return true;
}

string Entity::GetName() {
    return name;
}

string Entity::GetTitle() {
    return title;
}