#ifndef ENGINE_H
#define ENGINE_H
#include <map>
#include <sstream>

class Parseley3;
class Position;
class Floor;

#include "verbs.h"
#include "entity.h"
#include "location.h"
#include "position.h"
#include "parseley.h"
#include "room.h"
#include "floor.h"

class Lexicon2 {
    public: 
        Lexicon2(Parseley3* _parseley);
        Lexicon2(std::string _startingFloor, Position* _startingPos, Parseley3* _parseley);


        void Run();

        bool AddFloor(Floor* _floor);

        Floor* GetFloor(std::string _currentFloor);
        


    private: 
        std::map<std::string, Floor*> floors;
        std::string currentFloor;
        Position* currentPosition;
        Parseley3* parseley;
};

#endif