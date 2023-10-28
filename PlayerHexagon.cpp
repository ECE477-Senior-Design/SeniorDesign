/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/27/2023
*/

#include "PlayerHexagon.hh"

//Constructor for player hex
PlayerHexagon::PlayerHexagon(int column, int row) : Hexagon(column, row) {
    _type = Player; //Sets type to player
    _weight = Impassable; //Sets weight to impassable
}