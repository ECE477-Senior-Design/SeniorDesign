/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/26/2023
*/

#ifndef WALLHEXAGON_HH
#define WALLHEXAGON_HH

#include "BaseHexagon.hh"

//Class definition of a wall hexagon, derived from base hexagon
class WallHexagon : public Hexagon {
    public:
        WallHexagon(int column, int row); //Constructor for wall hex
};

#endif