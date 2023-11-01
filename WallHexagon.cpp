/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/27/2023
*/

#include "WallHexagon.hh"

//Constructor for wall hex
WallHexagon::WallHexagon(int column, int row) : Hexagon(column, row) {
    _type = WallHex; //Sets type to wall
    _passable = false; //Sets weight to impassable
}