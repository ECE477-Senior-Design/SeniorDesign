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


//this acts as a placeholder and will be replaced with LCD communication later
void display_text(string text) {
    cout << text;
}

char fetch_input() {
    char input;
    cin >> input;
    return input;
}

vector<string> getMapandCharStrings(string filepath) {
    //read from file
    ifstream file(filepath);
    string input;
    vector<string> input_list;

    if(file) {
        display_text("File opened successfully\n\n");
    }
    else {
        display_text("File failed to open");
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
    display_text("Welcome to the Dungeon Crawler Board!\n");
    display_text("Get a map from memory (M) or download (D) a new one?\n");
    display_text("Enter M or D: ");
    while(1) {
        input = fetch_input();
        if (input == 'M') {
            cout << "Show options stored in memory" << endl;
            // This is part of stretch functionality: this would read a list of maps stored in memory and allow the user to select one
            break;
        }
        else if (input == 'D') {
            display_text("Show options to download a new map");
            // TODO: add a wait here for the USB communication to send a file, then
            // read the file and store it in game_input
            game_input = getMapandCharStrings("../src/input.txt");
            if(game_input.size() == 0) {
                display_text("Failed to read file. Exiting program");
                exit(1);
            }
            break;
        }
        else {
            display_text("Invalid input. Please enter M or D:");
        }
    }
    display_text("Map and characters loaded successfully\n\n");
    return game_input;
}

int main(int argc, char *argv[]) {
    
    vector<string> input = PromptGameStart();
    GameMap map = GameMap(input[0]);
    map.PrintMap();
    GameCharacters characters = GameCharacters(input);
    //initialize charactesr from input vector
    characters.GetCharacter(0)->DisplayCharacterInfo();

    //Implement turn based gameplay here

    do 
    {
        cout << '\n';
        display_text("Press a key to start the game...");
    } while (cin.get() != '\n');
    cin.get();

    display_text("Game has begun!\n\n");
    display_text("It is ");
    display_text(characters.GetCharacter(0)->GetName());
    display_text("'s turn\n");
    
    return 0;
}