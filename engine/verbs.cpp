#include "verbs.h"
#include "entity.h"
#include <iostream>
#include <map>

Verb::Verb(std::string _word) {
    word = _word;
}

std::string Verb::GetWord() {
    return word;
}

bool Verb::AddPreposition(Preposition* _preposition) {
    prepositions[_preposition->prep] = _preposition;
    return true;
}

std::map<std::string, Preposition*> Verb::GetPrepositions() {
    return prepositions;
}

void Verb::ExecutePreposition(std::string _prep, Entity* _entity, Lexicon2* engine) {
    Preposition _preposition;
    
    auto it = prepositions.find(_prep);

    if (it != prepositions.end()) {
        _preposition = *it->second;
        _preposition.function(_entity, engine);
    }
}