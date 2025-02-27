#ifndef MAP_H
#define MAP_H
    #include <string>
    #include <iostream>
    #include <vector>
    #include <map>
    #include "room.h"
    using namespace std;

    class Map {
        public: 
            Map(string _name);

            bool AddRoom(Room *room);

            Room* GetRoom(Position position);

            Room* GetRoom(int _x, int _y, int _z);

            Room* GetRoom(string _name);
        private:
            string name;
            map<string, Room*> rooms;
    };
#endif