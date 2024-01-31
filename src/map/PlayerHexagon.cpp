/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/31/2023
*/

#include "PlayerHexagon.hh"

//Constructor for player hex
PlayerHexagon::PlayerHexagon(int column, int row) : Hexagon(column, row) {
    _type = PlayerHex; //Sets type to player
    _passable = false; //Sets weight to impassable
}