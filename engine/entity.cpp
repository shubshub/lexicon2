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
    if (!_verb || !_prep) {
        return nullptr;
    }

    for (VerbPrepositionCombo* action : actions) {
        const bool wordMatch = action->verb->GetWord() == _verb->GetWord();
        const bool prepMath = action->preposition->prep == _prep->prep;

        if (wordMatch && prepMath) {
            return action;
        }
    }

    return nullptr;
}
//std::function<void(Entity* Lexicon2*)> function;
Entity* Entity::CreateAction(Verb* _verb, Preposition* _prep, void(*_function)(Lexicon2* engine)) {
    VerbPrepositionCombo* _vpc = new VerbPrepositionCombo();
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