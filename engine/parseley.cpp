#include <string>
#include <map>
#include <limits>
#include <sstream>
#include "verbs.h"
#include "entity.h"
#include "engine.h"

Parseley3::Parseley3() {}
        
void Parseley3::GrabVerbEntities(std::string _sentence, map<std::string, Entity*> _entities, Lexicon2* engine) {
    char anykey;
    map<std::string, Verb*> _verbs = GetVerbs();
    

    std::vector<VerbEntityPrepCombo> _verbEntityCombos;

    std::istringstream ss(_sentence);
    std::string word;
    std::vector<std::string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    auto it = words.begin();
    while (it != words.end()) {
        if(_verbs.count(*it)) {
            VerbEntityPrepCombo _combo;
            std::string entry = *it;
            _combo.verb = _verbs.find(entry)->second;
            map<std::string, Preposition*> _prepositions = _combo.verb->GetPrepositions();
            FindPrepositions(&_combo, words, _prepositions);
            FindEntities(&_combo, words, _entities);
            _verbEntityCombos.push_back(_combo);
        }

        // Erase the element after processing
        it = words.erase(it);  // erase returns the next iterator

        // No need to increment it manually as erase already moves it to the next element
    }

    for (int i = 0; i < _verbEntityCombos.size(); i++) {
        VerbEntityPrepCombo _vpc = _verbEntityCombos[i];

        Verb* _verb = _vpc.verb;
        if (!_verb) {
            continue;
        }

        Preposition* _prep = _vpc.preposition;
        if (!_prep) {
            continue;
        }

        VerbPrepositionCombo* validAction = _vpc.entity->GetAction(_verb, _prep);
        if (!validAction) {
            continue;
        }
        
        validAction->preposition->function(_vpc.entity, engine);
        std::cout << std::endl;
        validAction->function(engine);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards until a newline

    
}

void Parseley3::FindPrepositions(VerbEntityPrepCombo* _combo, std::vector<std::string> _words, map<std::string, Preposition*> _prepositions) {
    for (int i = 0; i < _words.size(); i++) {
        if(_prepositions.count(_words[i])) {;
            _combo->preposition = _prepositions.find(_words[i])->second;
            break;
        }
    }
}

void Parseley3::FindEntities(VerbEntityPrepCombo* _combo, std::vector<std::string> _words, map<std::string, Entity*> _entities) {
    for (int i = 0; i < _words.size(); i++) {
        if(_entities.count(_words[i])) {
            _combo->entity = _entities.find(_words[i])->second;
            break;
        }
    }
}

map<std::string, Verb*> Parseley3::GetVerbs() {
    return verbs;
}

bool Parseley3::AddVerb(Verb* _verb) {
    verbs[_verb->GetWord()] = _verb;

    return true;
}