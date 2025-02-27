#include "map.h"

Map::Map(string _name) {
    name = _name;
};

bool Map::AddRoom(Room *room)  {
    rooms[room->GetName()] = room;

    return true;
}

Room* Map::GetRoom(Position position) {
    Room *_thisRoom;
    for (const auto& pair : rooms) {
        Position pos = pair.second->GetPosition();
        if (pos == position) {
            _thisRoom = pair.second;
        }
    }

    return _thisRoom;
}

Room* Map::GetRoom(int _x, int _y, int _z) {
    Room *_thisRoom;
    for (const auto& pair : rooms) {
        Position pos = pair.second->GetPosition();
        if (pos == Position(_x, _y, _z)) {
            _thisRoom = pair.second;
        }
    }

    return _thisRoom;
}

Room* Map::GetRoom(string _name) {
    Room* _thisRoom;
    auto it = rooms.find(_name);
    if (it != rooms.end()) {
        _thisRoom = it->second;
    }

    return _thisRoom;
}