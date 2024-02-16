#include "gameflow.hh"

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
    string input;
    vector<string> game_input;
    display_text("Welcome to the Dungeon Crawler Board!\n");
    display_text("Get a map from memory (M) or download (D) a new one?\n");
    display_text("Enter M or D: ");
    while(1) {
        input = fetch_input();
        if (input[0] == 'M') {
            cout << "Show options stored in memory" << endl;
            // This is part of stretch functionality: this would read a list of maps stored in memory and allow the user to select one
            break;
        }
        else if (input[0] == 'D') {
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

void startGame() {
    do 
    {
        cout << '\n';
        display_text("Press a key to start the game...");
    } while (cin.get() != '\n');
    cin.get();

    display_text("Game has begun!\n\n");
}

pair<int, int> get_move(void) {
    display_text("Move Character: ");
    display_text("column: ");
    string col = fetch_input();
    int col_num = stoi(col);
    display_text("row: ");
    string row = fetch_input();
    int row_num = stoi(row);
    return make_pair(col_num, row_num);
}

int game_loop(GameMap &map, GameCharacters &characters) {
    while(characters.GetNumberCharacters() > 1) {
        for(int i = 0; i < characters.GetNumberCharacters(); i++) {
            display_text("It is ");
            display_text(characters.GetCharacter(i)->GetName());
            display_text("'s turn\n\n");
            
            display_text("Enter Dice Roll: ");
            string roll = fetch_input();
            int roll_num = stoi(roll);
            pair<int, int> move = get_move();
          //  characters.GetCharacter(i)->MoveCharacter(move.first, move.second);
            map.PrintMap();

        //    display_text(roll);
          //  display_text("\n\n");


        }
    }
}