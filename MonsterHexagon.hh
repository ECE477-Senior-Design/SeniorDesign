/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/31/2023
*/

#ifndef MONSTERHEXAGON_HH
#define MONSTERHEXAGON_HH

#include "BaseHexagon.hh"

//Class definition for a monster hexagon, derived from base hexagon
class MonsterHexagon : public Hexagon {
    public:
        MonsterHexagon(int column, int row); //Constructor for hex
};

#endif