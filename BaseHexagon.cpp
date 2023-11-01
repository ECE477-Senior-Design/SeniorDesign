/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/31/2023
*/

#include "BaseHexagon.hh"

// //Constructor for hex
// Hexagon::Hexagon(int column, int row) {
//     _column = column; //Sets column position
//     _row = row; //Set row position
//     _type = BaseHex; //Default type is base
//     _weight = Passable; //Default weight is passable
// }

// //Returns column position of hex
// int Hexagon::GetColumn(void) {
//     return _column;
// }

// //Returns hex position of hex
// int Hexagon::GetRow(void) {
//     return _row;
// }

//Constructor for hex
Hexagon::Hexagon(int q, int r) {
    _q = q;
    _r = r;
    _type = BaseHex; //Default type is base
    _passable = true; //Default weight is passable
}

int Hexagon::GetQ(void) {
    return _q;
}

int Hexagon::GetR(void) {
    return _r;
}

//Returns type of hex
HexagonType Hexagon::GetType(void) {
    return _type;
}

// //Returns weight of hex
// Weight Hexagon::GetWeight(void) {
//     return _weight;
// }

bool Hexagon::GetPassable(void) {
    return _passable;
}

//Sets type of hex
void Hexagon::SetQ(int q) {
    _q = q;
}

//Sets weight of hex
void Hexagon::SetR(int r) {
    _r = r;
}

//Sets type of hex
void Hexagon::SetType(HexagonType type) {
    _type = type;
}

// //Sets weight of hex
// void Hexagon::SetWeight(Weight weight) {
//     _weight = weight;
// }

void Hexagon::SetPassable(bool passable) {
    _passable = passable;
}

//Destructor for hex
Hexagon::~Hexagon() {
}