#ifndef ENGINE_H
#define ENGINE_H
#include <map>
#include <sstream>
#include "floor.h"
#include "position.h"
#include "parseley.h"

class Lexicon2 {
    public: 
        Lexicon2(Parseley3* _parseley) {
            currentPosition = Position(0 , 0, 0);
            parseley = _parseley;
        }
        Lexicon2(std::string _startingFloor, Position _startingPos, Parseley3* _parseley) {
            currentFloor = _startingFloor;
            currentPosition = _startingPos;
            parseley = _parseley;
        }


        void Run() {
            while(true) {
                std::cout<< u8"\033[2J\033[1;1H"; 
                std::string _input;
                if(currentFloor == "" ){
                    currentFloor = floors.begin()->first;
                }
                Floor* _currentFloor = GetFloor(currentFloor);
                Room* _currentRoom = _currentFloor->GetRoom(currentPosition);
                map<std::string, Entity*> _entities = _currentRoom->GetEntities();
                _currentFloor->DescribeCurrentRoom(currentPosition);

                std::cout << "What would you like to do?\n";

                std::getline(std::cin, _input);

                parseley->GrabVerbEntities(_input, _entities);
            }
        }

        bool AddFloor(Floor* _floor) {
            floors[_floor->GetName()] = _floor;
            return true;
        }

        Floor* GetFloor(std::string _currentFloor) {
            Floor* _thisFloor;
            auto it = floors.find(_currentFloor);
            if (it != floors.end()) {
                _thisFloor = it->second;
            }
        
            return _thisFloor;
        }
        


    private: 
        std::map<std::string, Floor*> floors;
        std::string currentFloor;
        Position currentPosition;
        Parseley3* parseley;
};

#endif