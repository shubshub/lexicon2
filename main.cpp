#include <iostream>
#include <vector>
#include <string>
#include "engine/engine.h"

using namespace std;

void walkPrep(Entity* _entity, Lexicon2* engine) {
    std::cout << "You walk";
}

void sitChair(Lexicon2* engine) {
    std::cout << "You sit on the chair";
}

int main()
{
    Parseley3 _parseley = Parseley3();
    Verb _walk = Verb("walk");
    Verb _take = Verb("take");
    Preposition _prep;
    _prep.prep = "to";
    _prep.function = walkPrep;
    _walk.AddPreposition(&_prep);
    _parseley.AddVerb(&_walk);
    _parseley.AddVerb(&_take);
    Lexicon2 _gameInstance = Lexicon2(&_parseley);
    Entity _chairEntity = Entity("chair", "Chair");
    _chairEntity.CreateAction(&_walk, &_prep, &sitChair);
    Room _myRoom = Room("testroom", 0, 0, 0);
    Floor _myFloor = Floor("myMap");

    _myFloor.AddRoom(&_myRoom);
    _myRoom.AddEntity(&_chairEntity);
    _gameInstance.AddFloor(&_myFloor);
    _gameInstance.Run();
    

    return 0;
}