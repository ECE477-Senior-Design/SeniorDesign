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

//Arbitrary small to make it easier to see. Can adjust as needed
const int columns = 5;
const int rows = 5;

vector<string> getMapandCharStrings(string filepath) {
    //read from file
    ifstream file(filepath);
    string input;
    vector<string> input_list;

    if(file) {
        cout << "File opened successfully\n\n" << endl;
    }
    else {
        cout << "File failed to open" << endl;
        return(input_list);
    }

    while (getline(file, input)) {
    // Output the text from the file
    input_list.push_back(input);
    }

    // Close the file
    file.close();

    return(input_list);
}

vector<string> PromptGameStart() {
    char input;
    vector<string> game_input;
    cout << "Welcome to the Dungeon Crawler Board!\n" << endl;
    cout << "Get a map from memory (M) or download (D) a new one?" << endl;
    cout << "Enter M or D: ";
    while(1) {
        cin >> input;
        if (input == 'M') {
            cout << "Show options stored in memory" << endl;
            // This is part of stretch functionality: this would read a list of maps stored in memory and allow the user to select one
            break;
        }
        else if (input == 'D') {
            cout << "Show options to download a new map" << endl;
            // TODO: add a wait here for the USB communication to send a file, then
            // read the file and store it in game_input
            game_input = getMapandCharStrings("../src/input.txt");
            if(game_input.size() == 0) {
                cout << "Failed to read file. Exiting program" << endl;
                exit(1);
            }
            break;
        }
        else {
            cout << "Invalid input. Please enter M or D:";
        }
    }
    cout << "Map and characters loaded successfully\n\n" << endl;
    return game_input;
}

int main(int argc, char *argv[]) {
    
    vector<string> input = PromptGameStart();
    GameMap map = GameMap(input[0]);
    map.PrintMap();

    //initialize charactesr from input vector
    
    return 0;
}