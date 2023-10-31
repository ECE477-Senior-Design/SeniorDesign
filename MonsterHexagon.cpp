/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/31/2023
*/

#include "MonsterHexagon.hh"

//Constructor for monster hex
MonsterHexagon::MonsterHexagon(int column, int row) : Hexagon(column, row) {
    _type = MonsterHex; //Sets type to monster
    _weight = Impassable; //Sets weight to impassable
}