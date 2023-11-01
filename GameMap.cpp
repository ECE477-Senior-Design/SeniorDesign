/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/31/2023
*/

#include "GameMap.hh"

GameMap::GameMap(int columns, int rows) : _columns(columns), _rows(rows) {
    map.resize(rows, std::vector<Hexagon*>(columns, nullptr));

    for (int r = 0; r < rows; r++) {
        int r_offset = -1 * (r / 2);
        for (int q = r_offset; q < columns + r_offset; q++) {
            map[r][q + floor(r / 2)] = new Hexagon(q, r);
        }
    }   
}

//Returns the number of columns
int GameMap::GetColumns(void) {
    return _columns;
}

//Returns the number of rows
int GameMap::GetRows(void) {
    return _rows;
}

//Returns pointer to the hex
Hexagon* GameMap::GetHex(int column, int row) {
    if (column >= 0 && column < _columns && row >= 0 && row < _rows) {
        return map[column][row];
    } 
    else {
        return nullptr;
    }
}

void GameMap::ChangeHex(int column, int row, HexagonType type) {
    Hexagon* hex = GetHex(column, row); //Retrieves hex from a position
    hex->SetType(type); //Sets the new type of the position
    if (type == BaseHex) {
        hex->SetPassable(true); //Sets to passable is desired type is base
    }
    else {
        hex->SetPassable(false); //Sets to impassable is desired type is not base
    }
}

// //Returns the array of distances for a starting point
// std::vector<std::vector<int>> GameMap::ShortestPath(int start_column, int start_row) {
//     std::vector<std::vector<int>> distances(_columns, std::vector<int>(_rows, INT_MAX)); //Initialize a 2D vector for storing the distances
//     std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq; //Create a priority queue for Dijkstra's Algorithm
//     distances[start_column][start_row] = 0; //Set the distance to the starting hexagon to 0
//     pq.push(Node(start_column, start_row, 0)); //Start queue with initial position (since it's already traveled) 
//     int dx[] = {1, 0, -1, -1, 0, 1}; //Direction for each neighboring hex for x-coordinate (I am not entirely sure how it is oriented)
//     int dy[] = {0, 1, 1, 0, -1, -1}; //Direction for each neighboring hex for y-coordinate (I am not entirely sure how it is oriented)

//     //Checks if queue is empty
//     while (!pq.empty()) {
//         Node current = pq.top(); //Current node starts at the top
//         pq.pop(); //Pop the first node

//         //Checks each possible neighboring hex
//         for (int i = 0; i < 6; i++) {
//             int new_column = current.column + dx[i]; //Travels in x-direction
//             int new_row = current.row + dy[i]; //Travels in y-direction

//             //Checks if it is within the bounds of the map
//             if (new_column >= 0 && new_column < _columns && new_row >= 0 && new_row < _rows) {
//                 int weight = GetHex(new_column, new_row)->GetWeight(); //Weight is retrieved from hex at the new column and row position

//                 //Checks if the new distance is greater than the current distance
//                 if (distances[current.column][current.row] + weight < distances[new_column][new_row]) {
//                     distances[new_column][new_row] = distances[current.column][current.row] + weight; //Adds weight of newly traveled hex
//                     pq.push(Node(new_column, new_row, distances[new_column][new_row])); //Pushes the node onto the stack
//                 }
//             }
//         }
//     }

//     return distances;
// }

// //Prints out the path from a starting point to an ending point (function calls ShortestPath)
// void GameMap::PrintShortestPath(int start_column, int start_row, int end_column, int end_row) {
//     std::vector<std::vector<int>> distances = ShortestPath(start_column, start_row); //Calls ShortestPath and uses matrix of distances from starting point

//     //Checks if it is within the bounds of the map
//     if (end_column >= 0 && end_column < _columns && end_row >= 0 && end_row < _rows) {
//         std::stack<std::pair<int, int>> path; //Create a stack to store the path
//         int column = end_column; //Sets column to the desired column
//         int row = end_row; //Sets row to the desired row

//         //Backtrack from the destination to the source using distances
//         while (column != start_column || row != start_row) {
//             path.push(std::make_pair(column, row)); //Pushes column and row onto the stack
//             int dx[] = {1, 0, -1, -1, 0, 1}; //Direction for each neighboring hex for x-coordinate (I am not entirely sure how it is oriented)
//             int dy[] = {0, 1, 1, 0, -1, -1}; //Direction for each neighboring hex for y-coordinate (I am not entirely sure how it is oriented)

//             //Checks each possible neighboring hex
//             for (int i = 0; i < 6; i++) {
//                 int new_column = column + dx[i]; //Travels in x-direction
//                 int new_row = row + dy[i]; //Travels in y-direction

//                 //Checks if it is within the bounds of the map
//                 if (new_column >= 0 && new_column < _columns && new_row >= 0 && new_row < _rows) {
//                     int weight = GetHex(new_column, new_row)->GetWeight(); //Weight is retrieved from hex at the new column and row position

//                     //Checks if the new distance is equal to the current distance
//                     if (distances[column][row] == distances[new_column][new_row] + weight) {
//                         column = new_column; //Sets the column to the new column
//                         row = new_row; //Sets the row to the new row
//                         break;
//                     }
//                 }
//             }
//         }
//         path.push(std::make_pair(start_column, start_row)); //Pushes the starting column and row to the stack

//         std::cout << "Shortest path from (" << start_column << ", " << start_row << ") to (" << end_column << ", " << end_row << "): "; //Prints starting and ending locations
//         //Print the path in reverse order of the stack
//         while (!path.empty()) {
//             std::pair<int, int> hex = path.top(); //New hex is at the top of the stack
//             std::cout << "(" << hex.first << ", " << hex.second << ") "; //Prints the column and row of the traveled hex
//             path.pop(); //Pops the hex out of the stack
//         }
//         std::cout << std::endl;
//         } 
//         else {
//         std::cout << "Destination is out of bounds." << std::endl; //If stack is empty, then destination is not reachable
//     }
// }

std::vector<Hexagon*> GameMap::GetNeighbors(Hexagon* hexagon) {
    std::vector<Hexagon*> neighbors;
    int q = hexagon->GetQ();
    int r = hexagon->GetR();
    const std::vector<int> dq = {1, 1, 0, -1, -1, 0};
    const std::vector<int> dr = {0, -1, -1, 0, 1, 1};

    for (int i = 0; i < 6; ++i) {
        int neighbor_q = q + dq[i];
        int neighbor_r = r + dr[i];

        if (neighbor_q >= 0 && neighbor_q < _columns &&
            neighbor_r >= 0 && neighbor_r < _rows) {
            neighbors.push_back(GetHex(neighbor_q, neighbor_r));
        }
    }

    return neighbors;
}

//Function does not work for now. It keeps missing the last element
std::vector<Hexagon*> GameMap::BreadthFirstSearch(Hexagon* start, int movement) {
    std::queue<std::pair<Hexagon*, int>> queue;
    std::vector<Hexagon*> visited;
    queue.push({start, 0});
    visited.push_back(start);

    while (!queue.empty()) {
        Hexagon* current = queue.front().first;
        int current_movement = queue.front().second;
        queue.pop();
        std::vector<Hexagon*> neighbors = GetNeighbors(current);

        if (current_movement >= movement) {
            continue;
        }

        for (Hexagon* neighbor : neighbors) {
            if (std::find(visited.begin(), visited.end(), neighbor) == visited.end() && neighbor->GetPassable() == true) {
                queue.push({neighbor, current_movement + 1});
                visited.push_back(neighbor);
            }
        }
    }

    return visited;
}

void GameMap::PrintMap(void) {
    for (size_t q = 0; q < map.size(); q++) {
        if (q % 2 == 1) {
            std::cout << "        ";
        }
        for (size_t r = 0; r < map[q].size(); r++) {
            HexagonType type = map[q][r]->GetType();
            if (type == BaseHex) {
                std::string output = "Base ";
                std::cout << output << map[q][r]->GetQ() << " " << map[q][r]->GetR() << " ";
            }
            
        }
        std::cout << std::endl;
    }
}

//Destructor for the map
GameMap::~GameMap() {
    //Iterates through each position of the map
    for (int r = 0; r < _rows; r++) {
        for (int q = 0; q < _columns; q++) {
            //Checks to see if the map has a hex (it should always pass this)
            if (map[r][q] != nullptr) {
                delete map[r][q]; //Deletes hex
            }
        }
    }
}