#include "entity.h"
#include <string>
#include <iostream>
using namespace std;

Entity::Entity(string _name)  {
    name = _name;
}

bool Entity::Run()  {
    cout << "\n";
    cout << "Hello my name is " << name << " ";
    return true;
}

string Entity::GetName() {
    return name;
}