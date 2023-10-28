/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/27/2023
*/

#ifndef GAMEMAP_HH
#define GAMEMAP_HH

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include "BaseHexagon.hh"

//Node structure to keep track of column, row, and distance of each hex for shortest path
struct Node {
    int column;
    int row;
    int distance;

    Node(int column, int row, int distance) : column(column), row(row), distance(distance) {}

    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

//Class definiton for the game map and its associated functions
class GameMap {
    private:
        int _columns; //Number of columns in map (x-coordinate)
        int _rows; //Number of rows in map (y-coordinate)
        std::vector<std::vector<Hexagon*>> map; //Definition of map, using array of vectors, where each point is a hexagon

    public:
        GameMap(int columns, int rows); //Constructor for the map
        int GetColumns(void); //Returns the number of columns
        int GetRows(void); //Returns the number of rows
        void AddHex(int column, int row); //Adds a hex to the graph
        void Initialize(void); //Initializes a map to be all base hexes
        Hexagon* GetHex(int column, int row); //Returns pointer to the hex
        void ChangeHex(int column, int row, Type type); //Changes the hex based on the type input
        std::vector<std::vector<int>> ShortestPath(int start_column, int start_row); //Returns the array of distances for a starting point
        void PrintShortestPath(int start_column, int start_row, int end_column, int end_row); //Prints out the path from a starting point to an ending point (function calls ShortestPath)
        void Print(void); //Prints out the basic grid form of the map (maybe want to rename to PrintMap)
        ~GameMap(); //Destructor for the map
};

#endif