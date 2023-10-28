/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/27/2023
*/

#include "GameMap.hh"

//Constructor for the map
GameMap::GameMap(int columns, int rows) : _columns(columns), _rows(rows) {
    map.resize(columns, std::vector<Hexagon*>(rows, nullptr)); //Intializes the hexes to all be nullptrs
}

//Returns the number of columns
int GameMap::GetColumns(void) {
    return _columns;
}

//Returns the number of rows
int GameMap::GetRows(void) {
    return _rows;
}

//Adds a hex to the graph
void GameMap::AddHex(int column, int row) {
    Hexagon* hex = new Hexagon(column, row); //Constructs a new hex with a position
    map[column][row] = hex; //Assigns hex to a positon
}

//Initializes a map to be all base hexes
void GameMap::Initialize(void) {
    for (int i = 0; i < _columns; i++) {
        for (int j = 0; j < _rows; j++) {
            AddHex(i, j); //Adds a base hex to each position in the map
        }
    }
}

//Returns pointer to the hex
Hexagon* GameMap::GetHex(int column, int row) {
    return map.at(column).at(row);
}

//Changes the hex based on the type input
void GameMap::ChangeHex(int column, int row, Type type) {
    Hexagon* hex = GetHex(column, row); //Retrieves hex from a position
    hex->SetType(type); //Sets the new type of the position
    if (type == Base) {
        hex->SetWeight(Passable); //Sets to passable is desired type is base
    }
    else {
        hex->SetWeight(Impassable); //Sets to impassable is desired type is not base
    }
}

//Returns the array of distances for a starting point
std::vector<std::vector<int>> GameMap::ShortestPath(int start_column, int start_row) {
    std::vector<std::vector<int>> distances(_columns, std::vector<int>(_rows, INT_MAX)); //Initialize a 2D vector for storing the distances
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq; //Create a priority queue for Dijkstra's Algorithm
    distances[start_column][start_row] = 0; //Set the distance to the starting hexagon to 0
    pq.push(Node(start_column, start_row, 0)); //Start queue with initial position (since it's already traveled) 
    int dx[] = {1, 0, -1, -1, 0, 1}; //Direction for each neighboring hex for x-coordinate (I am not entirely sure how it is oriented)
    int dy[] = {0, 1, 1, 0, -1, -1}; //Direction for each neighboring hex for y-coordinate (I am not entirely sure how it is oriented)

    //Checks if queue is empty
    while (!pq.empty()) {
        Node current = pq.top(); //Current node starts at the top
        pq.pop(); //Pop the first node

        //Checks each possible neighboring hex
        for (int i = 0; i < 6; i++) {
            int new_column = current.column + dx[i]; //Travels in x-direction
            int new_row = current.row + dy[i]; //Travels in y-direction

            //Checks if it is within the bounds of the map
            if (new_column >= 0 && new_column < _columns && new_row >= 0 && new_row < _rows) {
                int weight = GetHex(new_column, new_row)->GetWeight(); //Weight is retrieved from hex at the new column and row position

                //Checks if the new distance is greater than the current distance
                if (distances[current.column][current.row] + weight < distances[new_column][new_row]) {
                    distances[new_column][new_row] = distances[current.column][current.row] + weight; //Adds weight of newly traveled hex
                    pq.push(Node(new_column, new_row, distances[new_column][new_row])); //Pushes the node onto the stack
                }
            }
        }
    }

    return distances;
}

//Prints out the path from a starting point to an ending point (function calls ShortestPath)
void GameMap::PrintShortestPath(int start_column, int start_row, int end_column, int end_row) {
    std::vector<std::vector<int>> distances = ShortestPath(start_column, start_row); //Calls ShortestPath and uses matrix of distances from starting point

    //Checks if it is within the bounds of the map
    if (end_column >= 0 && end_column < _columns && end_row >= 0 && end_row < _rows) {
        std::stack<std::pair<int, int>> path; //Create a stack to store the path
        int column = end_column; //Sets column to the desired column
        int row = end_row; //Sets row to the desired row

        //Backtrack from the destination to the source using distances
        while (column != start_column || row != start_row) {
            path.push(std::make_pair(column, row)); //Pushes column and row onto the stack
            int dx[] = {1, 0, -1, -1, 0, 1}; //Direction for each neighboring hex for x-coordinate (I am not entirely sure how it is oriented)
            int dy[] = {0, 1, 1, 0, -1, -1}; //Direction for each neighboring hex for y-coordinate (I am not entirely sure how it is oriented)

            //Checks each possible neighboring hex
            for (int i = 0; i < 6; i++) {
                int new_column = column + dx[i]; //Travels in x-direction
                int new_row = row + dy[i]; //Travels in y-direction

                //Checks if it is within the bounds of the map
                if (new_column >= 0 && new_column < _columns && new_row >= 0 && new_row < _rows) {
                    int weight = GetHex(new_column, new_row)->GetWeight(); //Weight is retrieved from hex at the new column and row position

                    //Checks if the new distance is equal to the current distance
                    if (distances[column][row] == distances[new_column][new_row] + weight) {
                        column = new_column; //Sets the column to the new column
                        row = new_row; //Sets the row to the new row
                        break;
                    }
                }
            }
        }
        path.push(std::make_pair(start_column, start_row)); //Pushes the starting column and row to the stack

        std::cout << "Shortest path from (" << start_column << ", " << start_row << ") to (" << end_column << ", " << end_row << "): "; //Prints starting and ending locations
        //Print the path in reverse order of the stack
        while (!path.empty()) {
            std::pair<int, int> hex = path.top(); //New hex is at the top of the stack
            std::cout << "(" << hex.first << ", " << hex.second << ") "; //Prints the column and row of the traveled hex
            path.pop(); //Pops the hex out of the stack
        }
        std::cout << std::endl;
        } 
        else {
        std::cout << "Destination is out of bounds." << std::endl; //If stack is empty, then destination is not reachable
    }
}

//Prints out the basic grid form of the map (maybe want to rename to PrintMap)
void GameMap::Print(void) {
    //Iterates through each position of the map
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            //Checks if it is the start of the row
            if (j == 0) {
                std::cout << "Row " << i << ": "; //Prints row number
            }
            std::cout << "Column " << j << " "; //Prints column number
            Hexagon* hex = GetHex(i, j); //Retreives hex at a position
            int weight = hex->GetWeight(); //Finds weight of the hex
            std::cout << "Weight " << weight << " "; //Prints weight of the hex
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//Destructor for the map
GameMap::~GameMap() {
    //Iterates through each position of the map
    for (int i = 0; i < _columns; i++) {
        for (int j = 0; j < _rows; j++) {
            //Checks to see if the map has a hex (it should always pass this)
            if (map[i][j] != nullptr) {
                delete map[i][j]; //Deletes hex
            }
        }
    }
}