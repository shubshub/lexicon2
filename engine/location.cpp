#include "location.h"

Location::Location() {
    name = "Deck";
}

Location::Location(string _name, string _title) {
    name = _name;
    title = _title;
}

string Location::GetName() {
    return name;
}

string Location::GetTitle() {
    return title;
}

map<string, Entity*> Location::GetEntities() {
    return entities;
}

bool Location::AddEntity(Entity* entity) {
    entities[entity->GetName()] = entity;

    return true;
}