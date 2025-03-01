#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <map>

using namespace std;

class Entity;

class Location {
    public: 
        Location();
        Location(string _name, string _title);
        string GetName();
        string GetTitle();

        bool AddEntity(Entity* entity);
        map<string, Entity*> GetEntities();
    private:
        string name;
        string title;
        map<string, Entity*> entities;
};
#endif