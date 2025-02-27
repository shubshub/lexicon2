#include "room.h"

#include <iostream>
#include <map>
#include <string>
using namespace std;

Room::Room(string _name, int _x, int _y, int _z) {
                
    name = _name;
    position = Position(_x, _y, _z);

}

Room::Room(string _name, Position _position) {
                
    name = _name;
    position = _position;

}

Room::Room() {
    name = "";
    position = Position();
}

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
    }

    return _thisEntity;
}

Position Room::GetPosition() {
    return position;
}