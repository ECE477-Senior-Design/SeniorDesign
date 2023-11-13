/*
MOST RECENT AUTHOR: JACKSON
DATE: 11/01/2023
*/

/*
If you want to run, do make, then ./test
NOTE: NEEDS TO BE RAN ON A LINUX SYSTEM OR ECEPROG. WE NEED TO DISCUSS IF WANT TO DO LINUX OR WINDOWS
Next to do: Print out map in a more meaningful way to better see result of code
*/

#include "GameMap.hh"
#include "GameCharacters.hh"

//Arbitrary small to make it easier to see. Can adjust as needed
const int columns = 5;
const int rows = 5;

// //Test creating a map, changing hex types, and shortest path algorithm
// void MapTest(void) {
//     GameMap map(columns, rows); //Allocates memory for map

//     map.Initialize(); //Initializes hex grid to be all base hexagons

//     // map.ChangeHex(0, 0, Wall);
//     // map.ChangeHex(1, 1, Wall);
//     // map.ChangeHex(2, 2, Wall);
//     // map.ChangeHex(3, 3, Wall);
//     // map.ChangeHex(4, 4, Wall);
//     // map.ChangeHex(0, 1, Wall);
//     // map.ChangeHex(0, 1, Base);

//     map.ChangeHex(1, 0, WallHex); //Creating an obstacle

//     int start_column = 0;
//     int start_row = 0;
//     int end_column = 2;
//     int end_row = 0;
//     map.PrintShortestPath(start_column, start_row, end_column, end_row); //Sees if it finds a path around the wall (it does)

//     map.Print(); //Prints a generic grid structure of the hex map
// }

// //Tests creating characters and adding them to a vector of characters using user input
// void CharacterTest(void) {
//     GameMap map(columns, rows);
//     map.Initialize();
    
//     int number_players;
//     int number_monsters;
//     std::cout << "Enter the number of players you would like to have: ";
//     std::cin >> number_players;
//     std::cout << "You entered: " << number_players << std::endl;
//     std::cout << "Enter the number of monsters you would like to have: ";
//     std::cin >> number_monsters;
//     std::cout << "You entered: " << number_monsters << std::endl;
//     int number_characters = number_players + number_monsters;
//     GameCharacters characters(number_characters);

//     int column;
//     int row;
//     int strength;
//     int dexterity;
//     int constitution;
//     int intelligence;
//     int wisdom;
//     int charisma;
//     int max_health_points;
//     int current_health_points;
//     int armor_class;
//     int initiative;
//     int speed;
//     int class_int;
//     Class class_;

//     for (int i = 1; i <= number_players; i++) {
//         std::cout << "Enter the column position of Player " << i << " : ";
//         std::cin >> column;
//         std::cout << "You entered: " << column << std::endl;
//         std::cout << "Enter the row position of Player " << i << " : ";
//         std::cin >> row;
//         std::cout << "You entered: " << row << std::endl;
//         std::cout << "Enter the strength of Player " << i << " : ";
//         std::cin >> strength;
//         std::cout << "You entered: " << strength << std::endl;
//         std::cout << "Enter the dexterity of Player " << i << " : ";
//         std::cin >> dexterity;
//         std::cout << "You entered: " << dexterity << std::endl;
//         std::cout << "Enter the constitution of Player " << i << " : ";
//         std::cin >> constitution;
//         std::cout << "You entered: " << constitution << std::endl;
//         std::cout << "Enter the intelligence of Player " << i << " : ";
//         std::cin >> intelligence;
//         std::cout << "You entered: " << intelligence << std::endl;
//         std::cout << "Enter the wisdom of Player " << i << " : ";
//         std::cin >> wisdom;
//         std::cout << "You entered: " << wisdom << std::endl;
//         std::cout << "Enter the charisma of Player " << i << " : ";
//         std::cin >> charisma;
//         std::cout << "You entered: " << charisma << std::endl;
//         std::cout << "Enter the max health points of Player " << i << " : ";
//         std::cin >> max_health_points;
//         std::cout << "You entered: " << max_health_points << std::endl;
//         std::cout << "Enter the current health points of Player " << i << " : ";
//         std::cin >> current_health_points;
//         std::cout << "You entered: " << current_health_points << std::endl;
//         std::cout << "Enter the armor class of Player " << i << " : ";
//         std::cin >> armor_class;
//         std::cout << "You entered: " << armor_class << std::endl;
//         std::cout << "Enter the initiative of Player " << i << " : ";
//         std::cin >> initiative;
//         std::cout << "You entered: " << initiative << std::endl;
//         std::cout << "Enter the speed of Player " << i << " : ";
//         std::cin >> speed;
//         std::cout << "You entered: " << speed << std::endl;
//         std::cout << "Enter the class of Player " << i << " (0 == Fighter): ";
//         std::cin >> class_int;
//         std::cout << "You entered: " << class_int << std::endl;
//         if (class_int == 0) {
//             class_ = Fighter;
//         }
//         CharacterType character_type = Player;
//         HexagonType hexagon_type = PlayerHex;

//         characters.AddCharacter(i - 1, column, row, 
//         strength, dexterity, constitution, intelligence, wisdom, charisma,
//         max_health_points, current_health_points, armor_class, initiative, speed, character_type, class_);
//         map.ChangeHex(column, row, hexagon_type);
//         HexagonType test = map.GetHex(column, row)->GetType();
//         if (test == PlayerHex) {
//             std::cout << "Changed to PlayerHex" << std::endl;
//         }
//     }

//     for (int j = 1; j <= number_monsters; j++) {
//         std::cout << "Enter the column position of Monster " << j << " : ";
//         std::cin >> column;
//         std::cout << "You entered: " << column << std::endl;
//         std::cout << "Enter the row position of Monster " << j << " : ";
//         std::cin >> row;
//         std::cout << "You entered: " << row << std::endl;
//         std::cout << "Enter the strength of Monster " << j << " : ";
//         std::cin >> strength;
//         std::cout << "You entered: " << strength << std::endl;
//         std::cout << "Enter the dexterity of Monster " << j << " : ";
//         std::cin >> dexterity;
//         std::cout << "You entered: " << dexterity << std::endl;
//         std::cout << "Enter the constitution of Monster " << j << " : ";
//         std::cin >> constitution;
//         std::cout << "You entered: " << constitution << std::endl;
//         std::cout << "Enter the intelligence of Monster " << j << " : ";
//         std::cin >> intelligence;
//         std::cout << "You entered: " << intelligence << std::endl;
//         std::cout << "Enter the wisdom of Monster " << j << " : ";
//         std::cin >> wisdom;
//         std::cout << "You entered: " << wisdom << std::endl;
//         std::cout << "Enter the charisma of Monster " << j << " : ";
//         std::cin >> charisma;
//         std::cout << "You entered: " << charisma << std::endl;
//         std::cout << "Enter the max health points of Monster " << j << " : ";
//         std::cin >> max_health_points;
//         std::cout << "You entered: " << max_health_points << std::endl;
//         std::cout << "Enter the current health points of Monster " << j << " : ";
//         std::cin >> current_health_points;
//         std::cout << "You entered: " << current_health_points << std::endl;
//         std::cout << "Enter the armor class of Monster " << j << " : ";
//         std::cin >> armor_class;
//         std::cout << "You entered: " << armor_class << std::endl;
//         std::cout << "Enter the initiative of Monster " << j << " : ";
//         std::cin >> initiative;
//         std::cout << "You entered: " << initiative << std::endl;
//         std::cout << "Enter the speed of Monster " << j << " : ";
//         std::cin >> speed;
//         std::cout << "You entered: " << speed << std::endl;
//         std::cout << "Enter the class of Monster " << j << " (0 == Fighter): ";
//         std::cin >> class_int;
//         std::cout << "You entered: " << class_int << std::endl;
//         if (class_int == 0) {
//             class_ = Fighter;
//         }
//         CharacterType character_type = Monster;
//         HexagonType hexagon_type = MonsterHex;

//         characters.AddCharacter(number_players + j - 1, column, row, 
//         strength, dexterity, constitution, intelligence, wisdom, charisma,
//         max_health_points, current_health_points, armor_class, initiative, speed, character_type, class_);
//         map.ChangeHex(column, row, hexagon_type);
//         HexagonType test = map.GetHex(column, row)->GetType();
//         if (test == MonsterHex) {
//             std::cout << "Changed to MonsterHex" << std::endl;
//         }
//     }    
// }

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
    //PrintTest();
    FieldOfViewTest();
    //FindClosestPlayerTest();

    return 0;
}