#ifndef ROOM_H
#define ROOM_H
    #include <string>
    #include <map>
    #include "entity.h"
    #include "position.h"
    #include "location.h"
    using namespace std;

    class Room {
        public:
            Room();
            
            Room(string _name, int _x, int _y, int _z) ;
            Room(string _name, Position _position);

            string GetName();

            bool AddEntity(Entity* entity);
            bool AddLocation(Location* location);
            bool DescribeRoom();

            Entity* GetEntity(string _name);
            map<string, Entity*> GetEntities();
            map<string, Location*> GetLocations();
            
            Position GetPosition();

            
        private:
            string name;
            Position position;
            map<string, Entity*> entities;
            map<string, Location*> locations;
    };
#endif