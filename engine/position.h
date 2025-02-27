#ifndef POSITION_H
#define POSITION_H
    class Position {
        public:
        Position();
        Position(int _x, int _y, int _z);

        bool operator==(const Position&);

        int x;
        int y;
        int z;
    };
#endif