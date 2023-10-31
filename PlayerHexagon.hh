/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/31/2023
*/

#ifndef PLAYERHEXAGON_HH
#define PLAYERHEXAGON_HH

#include "BaseHexagon.hh"

//Class definition for a player hexagon, derived from base hexagon
class PlayerHexagon : public Hexagon {
    public:
        PlayerHexagon(int column, int row); //Constructor for hex
};

#endif