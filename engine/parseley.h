#ifndef PARSELEY_H
#define PARSELEY_H
#include <string>
#include <map>
#include <limits>
#include <sstream>

class Verb;
class Entity;
struct Preposition;
struct VerbPrepositionCombo;
class Lexicon2;

struct VerbEntityPrepCombo {
    Verb* verb;
    Entity* entity; 
    Preposition* preposition;
};

class Parseley3 {
    public: 
        Parseley3();
        
        void GrabVerbEntities(std::string _sentence, map<std::string, Entity*> _entities, Lexicon2* engine);

        void FindPrepositions(VerbEntityPrepCombo* _combo, std::vector<std::string> _words, map<std::string, Preposition*> _prepositions);

        void FindEntities(VerbEntityPrepCombo* _combo, std::vector<std::string> _words, map<std::string, Entity*> _entities);

        map<std::string, Verb*> GetVerbs();

        bool AddVerb(Verb* _verb);

    private:
        map<std::string, Verb*> verbs;
};


#endif