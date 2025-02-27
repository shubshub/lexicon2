#include "room.h"

#include <iostream>
#include <map>
#include <string>
using namespace std;

string Room::GetName() {
    return name;
}

bool Room::AddEntity(Entity* entity) {
    entities[entity->GetName()] = entity;

    return true;
}

Entity* Room::GetEntity(string _name) {
    Entity* _thisEntity;
    auto it = entities.find(_name);
    if (it != entities.end()) {
        _thisEntity = it->second;
        return _thisEntity;
    }
}

WorldPosition Room::GetPosition() {
    return position;
}