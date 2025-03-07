#ifndef VERBS_H
#define VERBS_H
#include <iostream>
#include <map>
#include <functional>

class Entity;
class Lexicon2;

struct Preposition {
    std::string prep;
    std::function<void(Entity*, Lexicon2*)> function;
};

class Verb {
    public:
        Verb(std::string _word);

        std::string GetWord();
        
        bool AddPreposition(Preposition* _preposition);

        std::map<std::string, Preposition*> GetPrepositions();

        void ExecutePreposition(std::string _prep, Entity* _entity, Lexicon2* engine);

    private:
        std::string word;
        std::map<std::string, Preposition*> prepositions;

};

#endif