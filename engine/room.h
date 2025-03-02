#ifndef ROOM_H
#define ROOM_H
    #include <string>
    #include <map>

    class Position;
    class Entity;
    class Location;
    class Lexicon2;
    using namespace std;

    class Room {
        public:
            Room();
            
            Room(string _name, int _x, int _y, int _z) ;
            Room(string _name, Position* _position);

            string GetName();

            bool AddEntity(Entity* entity);
            bool AddLocation(Location* location);
            bool SetDescription(void(*_description)(map<string, Entity*> _entities, map<string, Location*> _locations, Lexicon2* engine));
            bool DescribeRoom(Lexicon2* engine);

            Entity* GetEntity(string _name);
            map<string, Entity*> GetEntities();
            map<string, Location*> GetLocations();
            
            Position* GetPosition();
            void defaultDescription(map<string, Entity*> _entities, map<string, Location*> _locations, Lexicon2* engine);
            
        private:
            
            string name;
            Position* position;
            void(*description)(map<string, Entity*> _entities, map<string, Location*> _locations, Lexicon2* engine) = nullptr;
            map<string, Entity*> entities;
            map<string, Location*> locations;
    };
#endif