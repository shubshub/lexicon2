#ifndef MAP_H
#define MAP_H
    #include <string>
    #include <iostream>
    #include <vector>
    #include <map>

    using namespace std;
    
    class Room;
    class Position;
    class Lexicon2;

    class Floor {
        public: 
        Floor(string _name);

            bool AddRoom(Room *room);

            Room* GetRoom(Position position);

            Room* GetRoom(int _x, int _y, int _z);

            Room* GetRoom(string _name);

            std::string GetName();

            void DescribeCurrentRoom(int _x, int _y, int _z, Lexicon2* engine);
            void DescribeCurrentRoom(Position _position, Lexicon2* engine);

        private:
            string name;
            map<string, Room*> rooms;
    };
#endif