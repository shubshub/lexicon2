#include <iostream>
#include <vector>
#include <string>
#include "engine/engine.h"
#include "engine/entity.h"
#include "engine/room.h"
#include "engine/floor.h"
#include "engine/verbs.h"

using namespace std;

int main()
{
    Lexicon2 _gameInstance = Lexicon2();
    Entity _myentity = Entity("chair", "Chair");
    Room _myRoom = Room("testroom", 0, 0, 0);
    Floor _myFloor = Floor("myMap");

    _myFloor.AddRoom(&_myRoom);
    _myRoom.AddEntity(&_myentity);
    _gameInstance.AddFloor(&_myFloor);
    _gameInstance.Run();
    

    return 0;
}