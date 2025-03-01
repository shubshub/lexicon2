#ifndef ENTITY_H
#define ENTITY_H
    #include <string>
    #include <iostream>
    #include <map>
    #include <vector>
    using namespace std;

    class Verb;
    struct Preposition;
    class Lexicon2;

    struct VerbPrepositionCombo {
        Verb* verb;
        Preposition* preposition;
        void(*function)(Lexicon2* engine);
    };

    class Entity {
        private:
            string name;
            string title;
            std::vector<VerbPrepositionCombo*> actions;
            map<std::string, bool> flags;
        public:
            Entity();
            Entity(string _name, string _title);

            bool DescribeEntity();

            string GetName();
            string GetTitle();
            
            std::vector<VerbPrepositionCombo*> GetActions();
            VerbPrepositionCombo* GetAction(Verb* _verb, Preposition* _prep);
            bool GetFlag(std::string _flag);

            Entity* CreateAction(Verb* _verb, Preposition* preposition, void(*_function)(Lexicon2* engine));
            Entity* SetFlag(std::string _flag, bool _value);

    };
#endif