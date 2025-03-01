#ifndef VERBS_H
#define VERBS_H
#include <iostream>
#include <map>
#include "entity.h"
struct Preposition {
    std::string prep;
    void(*function)(std::map<std::string, Entity*> entities);
};

class Verb {
    public:
        Verb(std::string _word) {
            word = _word;
        }

        std::string GetWord() {
            return word;
        }
        
        bool AddPreposition(std::string _prep, Preposition _preposition) {
            prepositions[_prep] = _preposition;
        }

        void ExecutePreposition(std::string _prep, std::map<std::string, Entity*> _entities) {
            Preposition _preposition;
            
            auto it = prepositions.find(_prep);

            if (it != prepositions.end()) {
                _preposition = it->second;
                _preposition.function(_entities);
            }
        }

    private:
        std::string word;
        std::map<std::string, Preposition> prepositions;

};

#endif