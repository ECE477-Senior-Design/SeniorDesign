/*
MOST RECENT AUTHOR: NEIL
DATE: 11/01/2023
*/

/*
NOTE: NEEDS TO BE RAN ON A LINUX SYSTEM OR ECEPROG. WE NEED TO DISCUSS IF WANT TO DO LINUX OR WINDOWS
Next to do: Print out map in a more meaningful way to better see result of code
*/

using namespace std;
#include <string>
#include <iostream>
#include <fstream>

#include "map/GameMap.hh"
#include "character/GameCharacters.hh"
#include "utils/utils.hh"
#include "gameplay/gameflow.hh"


//Arbitrary small to make it easier to see. Can adjust as needed
const int columns = 5;
const int rows = 5;

int main(int argc, char *argv[]) {
    
    vector<string> input = PromptGameStart();
    GameMap map = GameMap(input[0]);
    map.PrintMap();
    GameCharacters characters = GameCharacters(input);
    //initialize charactesr from input vector
   // characters.GetCharacter(0)->DisplayCharacterInfo();

    startGame();
    int result = game_loop(map, characters);
    return 0;
}