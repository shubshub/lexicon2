#ifndef MAP_H
#define MAP_H
    #include <string>
    #include <iostream>
    #include <vector>
    #include <map>
    #include "./room.h"
    using namespace std;

    class Map {
        public: 
            Map(string _name) {
                name = _name;
            };

            bool AddRoom(Room *room) {
                rooms[room->GetName()] = room;

                return true;
            }

            Room* GetRoom(string _name) {
                Room* _thisRoom;
                auto it = rooms.find(_name);
                if (it != rooms.end()) {
                    _thisRoom = it->second;
                }

                return _thisRoom;
            }
        private:
            string name;
            map<string, Room*> rooms;
    };
#endif