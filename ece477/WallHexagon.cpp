/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/26/2023
*/

#include "WallHexagon.hh"

//Constructor for wall hex
WallHexagon::WallHexagon(int column, int row) : Hexagon(column, row) {
    _type = Wall; //Sets type to wall
    _weight = WallWeight; //Sets weight to wall
}