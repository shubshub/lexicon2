#include "entity.h"
#include <string>
#include <iostream>

using namespace std;

Entity::Entity() {
    name = "";
    title = "";
}

Entity::Entity(string _name, string _title)  {
    name = _name;
    title = _title;
}

bool Entity::DescribeEntity()  {
    cout << "\n";
    cout << "I am a " << title << " sitting over by the " <<  "\n";
    return true;
}

std::vector<VerbPrepositionCombo*> Entity::GetActions() {
    return actions;
}

VerbPrepositionCombo* Entity::GetAction(Verb* _verb, Preposition* _prep) {
    VerbPrepositionCombo* _vpc;
    for (int i = 0; i < actions.size(); i++) {
        if (actions[i]->verb->GetWord() == _verb->GetWord()
        && actions[i]->preposition->prep == _prep->prep) {
            _vpc = actions[i];
            break;
        }
    }

    return _vpc;
}

Entity* Entity::CreateAction(Verb* _verb, Preposition* _prep, void(*_function)()) {
    VerbPrepositionCombo* _vpc;
    _vpc->verb = _verb;
    _vpc->preposition = _prep;
    _vpc->function = _function;

    actions.push_back(_vpc);

    return this;
}

string Entity::GetName() {
    return name;
}

string Entity::GetTitle() {
    return title;
}