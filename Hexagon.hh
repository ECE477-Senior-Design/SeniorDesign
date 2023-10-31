/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/31/2023
*/

#ifndef HEXAGON_HH
#define HEXAGON_HH

#include <climits>

//Defines the type of hexes (eventually add chest and enemy)
enum HexagonType {
    BaseHex,
    WallHex,
    PlayerHex,
    MonsterHex,
};

//Includes weight for each hex (everything except for base should be high)
enum Weight {
    Passable = 1,
    Impassable = 10000,
};


#endif