

#include <map>
#include <sstream>

#include "verbs.h"
#include "entity.h"
#include "location.h"
#include "position.h"
#include "parseley.h"
#include "room.h"
#include "floor.h"
#include "engine.h"

Lexicon2::Lexicon2(Parseley3* _parseley) {
    Position _pos = Position(0, 0, 0);
    currentPosition = &_pos;
    parseley = _parseley;
}
Lexicon2::Lexicon2(std::string _startingFloor, Position* _startingPos, Parseley3* _parseley) {
    currentFloor = _startingFloor;
    currentPosition = _startingPos;
    parseley = _parseley;
}


void Lexicon2::Run() {
    while(true) {
        std::cout<< u8"\033[2J\033[1;1H"; 
        std::string _input;
        if(currentFloor == "" ){
            currentFloor = floors.begin()->first;
        }
        Floor* _currentFloor = GetFloor(currentFloor);
        Room* _currentRoom = _currentFloor->GetRoom(*currentPosition);
        map<std::string, Entity*> _entities = _currentRoom->GetEntities();
        _currentFloor->DescribeCurrentRoom(*currentPosition, this);

        std::cout << "What would you like to do?\n";

        std::getline(std::cin, _input);

        parseley->GrabVerbEntities(_input, _entities, this);
    }
}

bool Lexicon2::AddFloor(Floor* _floor) {
    floors[_floor->GetName()] = _floor;
    return true;
}

Floor* Lexicon2::GetFloor(std::string _currentFloor) {
    Floor* _thisFloor;
    auto it = floors.find(_currentFloor);
    if (it != floors.end()) {
        _thisFloor = it->second;
    }

    return _thisFloor;
}