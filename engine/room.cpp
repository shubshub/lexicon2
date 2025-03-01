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

map<string, Entity*> Room::GetEntities() {
    return entities;
}

map<string, Location*> Room::GetLocations() {
    return locations;
}

bool Room::DescribeRoom() {
    map<string, Entity*> _entities = GetEntities();
    cout << "Welcome to the " << GetName() << " room\n";
    cout << "On the floor of the room you see before you\n";
    for (const auto& _entity : _entities) {
        cout << _entity.second->GetTitle() << "\n";
    }

    map<string, Location*> _locations = GetLocations();

    for (const auto& _location : _locations) {
        Location* _loc = _location.second;
        cout << " Located over by the " << _loc->GetTitle() << "\n";
        map<string, Entity*> _ents = _loc->GetEntities();

        for (const auto& _entity : _entities) {
            cout << _entity.second->GetTitle() << "\n";
        }
    }

    return true;
}

bool Room::AddEntity(Entity* entity) {
    entities[entity->GetName()] = entity;

    return true;
}

bool Room::AddLocation(Location* location) {
    locations[location->GetName()] = location;

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