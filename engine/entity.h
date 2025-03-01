#ifndef ENTITY_H
#define ENTITY_H
    #include <string>
    #include <iostream>

    using namespace std;

    class Entity {
        private:
            string name;
            string title;
        public:
            Entity(string _name, string _title);

            bool DescribeEntity();

            string GetName();
            string GetTitle();
    };
#endif