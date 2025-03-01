#ifndef ENGINE_H
#define ENGINE_H
#include <map>
#include "floor.h"
#include "position.h"

class Lexicon2 {
    public: 
        Lexicon2() {
            currentPosition = Position(0 , 0, 0);
        }
        Lexicon2(std::string _startingFloor, Position _startingPos) {
            currentFloor = _startingFloor;
            currentPosition = _startingPos;
        }


        void Run() {
            if(currentFloor == "" ){
                currentFloor = floors.begin()->first;
            }
            Floor* _currentFloor = GetFloor(currentFloor);
            _currentFloor->DescribeCurrentRoom(currentPosition);
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
};

#endif