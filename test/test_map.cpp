/*
MOST RECENT AUTHOR: JACKSON
DATE: 11/01/2023
*/

/*
If you want to run, do make, then ./test
NOTE: NEEDS TO BE RAN ON A LINUX SYSTEM OR ECEPROG. WE NEED TO DISCUSS IF WANT TO DO LINUX OR WINDOWS
Next to do: Print out map in a more meaningful way to better see result of code
*/

#include "map/GameMap.hh"
#include "character/GameCharacters.hh"
#include "gameplay/gameflow.hh"

//Arbitrary small to make it easier to see. Can adjust as needed
const int columns = 5;
const int rows = 5;

//Test creating a map, changing hex types, and shortest path algorithm
void MapTest(void) {
    GameMap map(columns, rows); //Allocates memory for map

  //  map.Initialize(); //Initializes hex grid to be all base hexagons

    // map.ChangeHex(0, 0, Wall);
    // map.ChangeHex(1, 1, Wall);
    // map.ChangeHex(2, 2, Wall);
    // map.ChangeHex(3, 3, Wall);
    // map.ChangeHex(4, 4, Wall);
    // map.ChangeHex(0, 1, Wall);
    // map.ChangeHex(0, 1, Base);

    map.ChangeHex(1, 0, WallHex); //Creating an obstacle

    int start_column = 0;
    int start_row = 0;
    int end_column = 2;
    int end_row = 0;
   // map.PrintShortestPath(start_column, start_row, end_column, end_row); //Sees if it finds a path around the wall (it does)

    map.PrintMap(); //Prints a generic grid structure of the hex map
}

void BreadthFirstSearchTest(void) {
    GameMap map(5, 5);
    Hexagon* start = map.GetHex(0, 0);
    map.ChangeHex(0, 2, WallHex);
    map.ChangeHex(1, 1, WallHex);
    map.ChangeHex(2, 1, WallHex);
    map.ChangeHex(2, 0, WallHex);
    std::vector<Hexagon*> reachable_hexes = map.PossibleMovements(start, 3);

    for (Hexagon* hex : reachable_hexes) {
        std::cout << "Hexagon at (" << hex->GetHexQ() << ", " << hex->GetHexR() << ") is reachable." << std::endl;
    }
}

void PrintTest(void) {
    GameMap map(5, 5);
    map.PrintMap();
}

void FieldOfViewTest(void) {
    GameMap map(5, 5);
    map.ChangeHex(0, 0, MonsterHex);
    map.ChangeHex(0, 1, WallHex);
    Hexagon* start = map.GetHex(0, 0);
    std::vector fov = map.FieldOfView(start, 3);
    for (Hexagon* hex : fov) {
        std::cout << hex->GetHexQ() << ", " << hex->GetHexR() << std::endl;
    }
}

void FindClosestPlayerTest(void) {
    GameMap map(5, 5);
    map.ChangeHex(0, 0, MonsterHex);
    map.ChangeHex(3, 2, PlayerHex);
    map.ChangeHex(0, 4, PlayerHex);
    map.ChangeHex(4, 3, PlayerHex);
    // Hexagon* start = map.GetHex(0, 0);
    // //std::vector<Hexagon*> characters_hexes = {map.GetHex(0, 0), map.GetHex(3, 2), map.GetHex(0, 4), map.GetHex(4, 3)};
    // map.ChangeHex(0, 1, PlayerHex);
    // std::vector<Hexagon*> characters_hexes = {map.GetHex(0, 0), map.GetHex(0, 1)};
    // std::vector<Hexagon*> closest_player_path = map.FindClosestPlayer(start, characters_hexes);
    // if (closest_player_path.size() > 0) {
    //     Hexagon* destination = closest_player_path.back();
    //     std::cout << destination->GetHexQ() << " " << destination->GetHexR() << std::endl;
    // }
}

int main(int argc, char *argv[]) {
    //MapTest();
    //CharacterTest();
    //BreadthFirstSearchTest();
    PrintTest();
   // FieldOfViewTest();
    //FindClosestPlayerTest();

    return 0;
}