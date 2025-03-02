#include <iostream>
#include <vector>
#include <string>
#include "engine/engine.h"

using namespace std;

void walkPrep(Entity* _entity, Lexicon2* engine) {
    std::cout << "You walk";
}

void sitTable(Lexicon2* engine) {
    std::cout << "You sit at the table";
}

void sitChair(Lexicon2* engine) {
    std::cout << "You sit on the chair";
}

void standChair(Lexicon2* engine) {
    std::cout << "You stand on the chair";
}

void takePrep(Entity* _entity, Lexicon2* engine) {
    std::cout << "You take";
}

void takeOver(Lexicon2* engine) {
    std::cout << "You take over the chair";
}

void takeThe(Lexicon2* engine) {
    std::cout << "You take the chair";
}

int main()
{
    Parseley3 _parseley = Parseley3();
    Verb _walk = Verb("walk");
    Verb _take = Verb("take");
    Preposition _to;
    _to.prep = "to";
    _to.function = walkPrep;
    _walk.AddPreposition(&_to);
    Preposition _on;
    _on.prep = "on";
    _on.function = walkPrep;
    _walk.AddPreposition(&_on);
    _parseley.AddVerb(&_walk);
    _parseley.AddVerb(&_take);

    Preposition _over;
    _over.prep = "over";
    _over.function = takePrep;
    _take.AddPreposition(&_over);

    Preposition _the;
    _the.prep = "the";
    _the.function = takePrep;
    _take.AddPreposition(&_the);

    
    Lexicon2 _gameInstance = Lexicon2(&_parseley);
    Entity _chairEntity = Entity("chair", "Chair");
    Entity _tableEntity = Entity("table", "Table");
    _chairEntity.CreateAction(&_walk, &_to, &sitChair);
    _chairEntity.CreateAction(&_walk, &_on, &standChair);
    _chairEntity.CreateAction(&_take, &_over, &takeOver);
    _chairEntity.CreateAction(&_take, &_the, &takeThe);
    _tableEntity.CreateAction(&_walk, &_to, &sitTable);


    Room _myRoom = Room("testroom", 0, 0, 0);
    
    Floor _myFloor = Floor("myMap");

    _myFloor.AddRoom(&_myRoom);
    _myRoom.AddEntity(&_chairEntity);
    _myRoom.AddEntity(&_tableEntity);
    _gameInstance.AddFloor(&_myFloor);
    _gameInstance.Run();
    

    return 0;
}