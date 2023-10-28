/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/27/2023
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

//Test creating a map, changing hex types, and shortest path algorithm
void MapTest(void) {
    GameMap map(columns, rows); //Allocates memory for map

    map.Initialize(); //Initializes hex grid to be all base hexagons

    // map.ChangeHex(0, 0, Wall);
    // map.ChangeHex(1, 1, Wall);
    // map.ChangeHex(2, 2, Wall);
    // map.ChangeHex(3, 3, Wall);
    // map.ChangeHex(4, 4, Wall);
    // map.ChangeHex(0, 1, Wall);
    // map.ChangeHex(0, 1, Base);

    map.ChangeHex(1, 0, Wall); //Creating an obstacle

    int start_column = 0;
    int start_row = 0;
    int end_column = 2;
    int end_row = 0;
    map.PrintShortestPath(start_column, start_row, end_column, end_row); //Sees if it finds a path around the wall (it does)

    map.Print(); //Prints a generic grid structure of the hex map
}

//Tests creating characters and adding them to a vector of characters using user input
void CharacterTest(void) {
    int number_characters;
    std::cout << "Enter the number of characters (both players and monsters) you would like to have: ";
    std::cin >> number_characters;
    std::cout << "You entered: " << number_characters << std::endl;
    GameCharacters characters(number_characters);

    int column;
    int row;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int max_health_points;
    int current_health_points;
    int armor_class;
    int initiative;
    int speed;
    //Class class_; //Figure out method to enter class (probably string)
    for (int i = 0; i < number_characters; i++) {
        std::cout << "Enter the column position of Character " << i << " : ";
        std::cin >> column;
        std::cout << "You entered: " << column << std::endl;
        std::cout << "Enter the row position of Character " << i << " : ";
        std::cin >> row;
        std::cout << "You entered: " << row << std::endl;
        std::cout << "Enter the strength of Character " << i << " : ";
        std::cin >> strength;
        std::cout << "You entered: " << strength << std::endl;
        std::cout << "Enter the dexterity of Character " << i << " : ";
        std::cin >> dexterity;
        std::cout << "You entered: " << dexterity << std::endl;
        std::cout << "Enter the constitution of Character " << i << " : ";
        std::cin >> constitution;
        std::cout << "You entered: " << constitution << std::endl;
        std::cout << "Enter the intelligence of Character " << i << " : ";
        std::cin >> intelligence;
        std::cout << "You entered: " << intelligence << std::endl;
        std::cout << "Enter the wisdom of Character " << i << " : ";
        std::cin >> wisdom;
        std::cout << "You entered: " << wisdom << std::endl;
        std::cout << "Enter the charisma of Character " << i << " : ";
        std::cin >> charisma;
        std::cout << "You entered: " << charisma << std::endl;
        std::cout << "Enter the max health points of Character " << i << " : ";
        std::cin >> max_health_points;
        std::cout << "You entered: " << max_health_points << std::endl;
        std::cout << "Enter the current health points of Character " << i << " : ";
        std::cin >> current_health_points;
        std::cout << "You entered: " << current_health_points << std::endl;
        std::cout << "Enter the armor class of Character " << i << " : ";
        std::cin >> armor_class;
        std::cout << "You entered: " << armor_class << std::endl;
        std::cout << "Enter the initiative of Character " << i << " : ";
        std::cin >> initiative;
        std::cout << "You entered: " << initiative << std::endl;
        std::cout << "Enter the speed of Character " << i << " : ";
        std::cin >> speed;
        std::cout << "You entered: " << speed << std::endl;

        characters.AddCharacter(i, column, row, 
        strength, dexterity, constitution, intelligence, wisdom, charisma,
        max_health_points, current_health_points, armor_class, initiative, speed, Fighter);
    }
}

int main(int argc, char *argv[]) {
    //MapTest();
    //CharacterTest();

    return 0;
}