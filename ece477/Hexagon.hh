/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/26/2023
*/

#ifndef HEXAGON_HH
#define HEXAGON_HH

#include <climits>

//Defines the type of hexes (eventually add chest and player/enemy)
enum Type {
    Base,
    Wall,
};

//Includes weight for each hex (everything except for base should be high)
enum Weight {
    BaseWeight = 1,
    WallWeight = 1000,
};


#endif