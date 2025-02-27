#ifndef ENTITY_H
#define ENTITY_H
    #include <string>
    #include <iostream>

    using namespace std;

    class Entity {
        private:
            string name;
        public:
            Entity(string _name);

            bool Run();

            string GetName();
    };
#endif