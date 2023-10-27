/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/26/2023
*/

/*
If you want to run, do make, then ./test
Next to do: Print out map in a more meaningful way to better see result of code
*/

#include "GameMap.hh"

//Arbitrary small to make it easier to see. Can adjust as needed
const int columns = 5;
const int rows = 5;

int main(int argc, char *argv[]) {
    GameMap map(columns, rows); //Allocates memory for map

    map.Initialize(); //Initializes hex grid to be all base hexagons

    //Just a test to see if ChangeHex worked (it does)
    /*map.ChangeHex(0, 0, Wall);
    map.ChangeHex(1, 1, Wall);
    map.ChangeHex(2, 2, Wall);
    map.ChangeHex(3, 3, Wall);
    map.ChangeHex(4, 4, Wall);
    map.ChangeHex(0, 1, Wall);
    map.ChangeHex(0, 1, Base);*/

    map.ChangeHex(1, 0, Wall); //Creating an obstacle

    int start_column = 0;
    int start_row = 0;
    int end_column = 2;
    int end_row = 0;
    map.PrintShortestPath(start_column, start_row, end_column, end_row); //Sees if it finds a path around the wall (it does)

    map.Print(); //Prints a generic grid structure of the hex map

    return 1;
}