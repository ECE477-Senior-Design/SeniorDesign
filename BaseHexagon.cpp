/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/26/2023
*/

#include "BaseHexagon.hh"

//Constructor for hex
Hexagon::Hexagon(int column, int row) {
    _column = column; //Sets column position
    _row = row; //Set row position
    _type = Base; //Default type is base
    _weight = BaseWeight; //Default weight is base
}

//Returns column position of hex
int Hexagon::GetColumn(void) {
    return _column;
}

//Returns hex position of hex
int Hexagon::GetRow(void) {
    return _row;
}

//Returns type of hex
Type Hexagon::GetType(void) {
    return _type;
}

//Returns weight of hex
Weight Hexagon::GetWeight(void) {
    return _weight;
}

//Sets type of hex
void Hexagon::SetType(Type type) {
    _type = type;
}

//Sets weight of hex
void Hexagon::SetWeight(Weight weight) {
    _weight = weight;
}

//Destructor for hex
Hexagon::~Hexagon(void) {
}