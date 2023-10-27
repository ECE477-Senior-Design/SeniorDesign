/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/26/2023
*/

#ifndef BASEHEXAGON_HH
#define BASEHEXAGON_HH

#include "Hexagon.hh"

//Class definition for a base hexagon
class Hexagon {
    protected:
        int _column; //Column position of hex
        int _row; //Row position of hex
        Type _type; //Type of hex
        Weight _weight; //Weight of hex

    public:
        Hexagon(int column, int row); //Constructor for hex
        int GetColumn(void); //Returns column position of hex
        int GetRow(void); //Returns hex position of hex
        Type GetType(void); //Returns type of hex
        Weight GetWeight(void); //Returns weight of hex
        void SetType(Type type); //Sets type of hex
        void SetWeight(Weight weight); //Sets weight of hex
        ~Hexagon(void); //Destructor for hex
};

#endif