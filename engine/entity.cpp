#include "entity.h"
#include "engine.h"
#include "verbs.h"
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

bool Entity::GetFlag(std::string _flag) {
    if (flags.count(_flag)) {
        return flags.find(_flag)->second;
    }

    return false;
}

Entity* Entity::SetFlag(std::string _flag, bool _value) {
    flags[_flag] = _value;
    return this;
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

Entity* Entity::CreateAction(Verb* _verb, Preposition* _prep, void(*_function)(Lexicon2* engine)) {
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