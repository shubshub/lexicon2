#include "room.h"
#include "position.h"
#include "location.h"
#include "entity.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

Room::Room(string _name, int _x, int _y, int _z) {
                
    name = _name;
    Position _pos = Position(_x, _y, _z);
    position = &_pos;

}

Room::Room(string _name, Position* _position) {
                
    name = _name;
    position = _position;

}

Room::Room() {
    name = "";
    Position _pos = Position();
    position = &_pos;
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

bool Room::SetDescription(void(*_description)(map<string, Entity*> _entities, map<string, Location*> _locations, Lexicon2* engine)) {
    description = _description;

    return true;
}

bool Room::DescribeRoom(Lexicon2* engine) {
    map<std::string, Entity*> _ents = GetEntities();
    map<std::string, Location*> _locs = GetLocations();
    if (!description) {
        defaultDescription(_ents, _locs, engine);
    } else {
        description(_ents, _locs, engine);
    }

    return true;
}

void Room::defaultDescription(map<string, Entity*> _entities, map<string, Location*> _locations, Lexicon2* engine) {
    cout << "Welcome to the " << GetName() << " room\n";
    cout << "On the floor of the room you see before you\n";
    for (const auto& _entity : _entities) {
        cout << _entity.second->GetTitle() << "\n";
    };

    for (const auto& _location : _locations) {
        Location* _loc = _location.second;
        cout << " Located over by the " << _loc->GetTitle() << "\n";
        map<string, Entity*> _ents = _loc->GetEntities();

        for (const auto& _entity : _entities) {
            cout << _entity.second->GetTitle() << "\n";
        }
    }
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

Position* Room::GetPosition() {
    return position;
}