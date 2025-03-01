#ifndef VERBS_H
#define VERBS_H
#include <iostream>
#include <map>


class Entity;
#include "entity.h"

struct Preposition {
    std::string prep;
    void(*function)(Entity* entity);
};

class Verb {
    public:
        Verb(std::string _word) {
            word = _word;
        }

        std::string GetWord() {
            return word;
        }
        
        bool AddPreposition(Preposition* _preposition) {
            prepositions[_preposition->prep] = _preposition;
            return true;
        }

        std::map<std::string, Preposition*> GetPrepositions() {
            return prepositions;
        }

        void ExecutePreposition(std::string _prep, Entity* _entity {
            Preposition _preposition;
            
            auto it = prepositions.find(_prep);

            if (it != prepositions.end()) {
                _preposition = *it->second;
                _preposition.function(_entity);
            }
        }

    private:
        std::string word;
        std::map<std::string, Preposition*> prepositions;

};

#endif