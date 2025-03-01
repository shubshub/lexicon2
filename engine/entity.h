#ifndef ENTITY_H
#define ENTITY_H
    #include <string>
    #include <iostream>
    #include <map>
    #include <vector>

    using namespace std;

    class Verb;
    struct Preposition;
    #include "verbs.h"

    struct VerbPrepositionCombo {
        Verb* verb;
        Preposition* preposition;
        void(*function)();
    };

    class Entity {
        private:
            string name;
            string title;
            std::vector<VerbPrepositionCombo*> actions;
        public:
            Entity();
            Entity(string _name, string _title);

            bool DescribeEntity();

            string GetName();
            string GetTitle();
            Entity* CreateAction(Verb* _verb, Preposition* preposition, void(*_function)());
            std::vector<VerbPrepositionCombo*> GetActions();
            VerbPrepositionCombo* GetAction(Verb* _verb, Preposition* _prep);

    };
#endif