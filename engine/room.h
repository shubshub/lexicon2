#ifndef ROOM_H
#define ROOM_H
    #include <string>
    #include <map>
    #include "./entity.h"
    #include "./worldposition.h"
    using namespace std;

    class Room {
        public:
            Room() {
                name = "";
                position = WorldPosition();
            }
            
            Room(string _name, int _x, int _y, int _z) {
                
                name = _name;
                position = WorldPosition(_x, _y, _z);

            }

            string GetName();

            bool AddEntity(Entity* entity);

            Entity* GetEntity(string _name);

            WorldPosition GetPosition();

            
        private:
            string name;
            WorldPosition position;
            map<string, Entity*> entities;
            int x;
            int y;
            int z;
    };
#endif