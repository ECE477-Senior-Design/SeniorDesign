/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/31/2023
*/

#ifndef BASEHEXAGON_HH
#define BASEHEXAGON_HH

#include "Hexagon.hh"

// //Class definition for a base hexagon
// class Hexagon {
//     protected:
//         int _column; //Column position of hex
//         int _row; //Row position of hex
//         HexagonType _type; //Type of hex
//         Weight _weight; //Weight of hex

//     public:
//         Hexagon(int column, int row); //Constructor for hex
//         int GetColumn(void); //Returns column position of hex
//         int GetRow(void); //Returns row position of hex
//         HexagonType GetType(void); //Returns type of hex
//         Weight GetWeight(void); //Returns weight of hex
//         void SetType(HexagonType type); //Sets type of hex
//         void SetWeight(Weight weight); //Sets weight of hex
//         ~Hexagon(); //Destructor for hex
// };

class Hexagon {
    protected:
        int _q;
        int _r;
        int _row;
        int _column;
        HexagonType _type;
        bool _passable;

    public:
        Hexagon(int q, int r);

        int GetHexQ(void);
        int GetHexR(void);
        int GetHexRow(void);
        int GetHexColumn(void);
        HexagonType GetType(void);
        bool GetPassable(void);

        void SetHexQ(int q);
        void SetHexR(int r);
        void SetHexRow(int row);
        void SetHexColumn(int column);
        void SetType(HexagonType type);
        void SetPassable(bool passable);

        ~Hexagon();
};

#endif