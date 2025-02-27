#include <iostream>
#include <vector>
#include <string>
#include "engine/entity.h"
#include "engine/room.h"
#include "engine/map.h"

using namespace std;

int main()
{
    Entity _myentity = Entity("Joey Bombano");
    Room _myRoom = Room("testroom", 0, 0, 1);
    cout << _myRoom.GetName();
    Map _myMap = Map("myMap");

    _myMap.AddRoom(&_myRoom);
    _myRoom.AddEntity(&_myentity);

    Room* _foundRoom = _myMap.GetRoom(Position(0, 0, 1));
    Entity* _foundEntity = _foundRoom->GetEntity("Joey Bombano");

    cout << "\nTesting Found Entity Reference\n";

    _foundEntity->Run();

    return 0;
}