#include "floor.h"
#include "room.h"
#include "position.h"

Floor::Floor(string _name) {
    name = _name;
};

bool Floor::AddRoom(Room *room)  {
    rooms[room->GetName()] = room;

    return true;
}

Room* Floor::GetRoom(Position position) {
    Room *_thisRoom;
    for (const auto& pair : rooms) {
        Position* pos = pair.second->GetPosition();
        if (*pos == position) {
            _thisRoom = pair.second;
        }
    }

    return _thisRoom;
}

Room* Floor::GetRoom(int _x, int _y, int _z) {
    Room *_thisRoom;
    for (const auto& pair : rooms) {
        Position* pos = pair.second->GetPosition();
        if (*pos == Position(_x, _y, _z)) {
            _thisRoom = pair.second;
        }
    }

    return _thisRoom;
}

void Floor::DescribeCurrentRoom(int _x, int _y, int _z, Lexicon2* engine) {
    Room* _thisRoom = GetRoom(_x, _y, _z);
    _thisRoom->DescribeRoom(engine);
}

std::string Floor::GetName() {
    return name;
}

void Floor::DescribeCurrentRoom(Position _position, Lexicon2* engine) {
    Room* _thisRoom = GetRoom(_position);
    _thisRoom->DescribeRoom(engine);
}

Room* Floor::GetRoom(string _name) {
    Room* _thisRoom;
    auto it = rooms.find(_name);
    if (it != rooms.end()) {
        _thisRoom = it->second;
    }

    return _thisRoom;
}