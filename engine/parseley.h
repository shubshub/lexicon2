#ifndef PARSELEY_H
#define PARSELEY_H
#include <string>
#include <map>
#include <limits>
#include "verbs.h"
#include "entity.h"

struct VerbEntityPrepCombo {
    Verb* verb;
    Entity* entity; 
    Preposition* preposition;
};

class Parseley3 {
    public: 
        Parseley3() {}
        
        void GrabVerbEntities(std::string _sentence, map<std::string, Entity*> _entities) {
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
                Preposition* _prep = _vpc.preposition;
                VerbPrepositionCombo* validAction = _vpc.entity->GetAction(_verb, _prep);
                validAction->preposition->function(_vpc.entity);
                validAction->function();
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards until a newline

            
        }

        void FindPrepositions(VerbEntityPrepCombo* _combo, std::vector<std::string> _words, map<std::string, Preposition*> _prepositions) {
            for (int i = 0; i < _words.size(); i++) {
                if(_prepositions.count(_words[i])) {;
                    _combo->preposition = _prepositions.find(_words[i])->second;
                    break;
                }
            }
        }

        void FindEntities(VerbEntityPrepCombo* _combo, std::vector<std::string> _words, map<std::string, Entity*> _entities) {
            for (int i = 0; i < _words.size(); i++) {
                if(_entities.count(_words[i])) {
                    _combo->entity = _entities.find(_words[i])->second;
                    break;
                }
            }
        }

        map<std::string, Verb*> GetVerbs() {
            return verbs;
        }

        bool AddVerb(Verb* _verb) {
            verbs[_verb->GetWord()] = _verb;

            return true;
        }

    private:
        map<std::string, Verb*> verbs;
};


#endif