#include <iostream>
#include <vector>
#include <string>
#include "./engine/entity.h"
#include "./engine/room.h"
#include "./engine/map.h"

using namespace std;

int main()
{
    Entity _myentity = Entity("Joey Bombano");


    /*_myMap.AddRoom(&_myRoom);
    _myRoom.AddEntity(&_myentity);

    Room* _foundRoom = _myMap.GetRoom("testroom");
    Entity* _foundEntity = _foundRoom->GetEntity("Joey Bombano");
    _foundEntity->Run();*/

    return 0;
}