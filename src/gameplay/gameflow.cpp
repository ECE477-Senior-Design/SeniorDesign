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

bool check_valid_move(pair<int, int> move, int roll, GameMap &map, Character &character) {
    Hexagon *start_hex = map.GetHex(character.GetColumn(), character.GetRow());
    Hexagon *end_hex = map.GetHex(move.first, move.second);

    if(end_hex->GetHexColumn() == start_hex->GetHexColumn() && end_hex->GetHexRow() == start_hex->GetHexRow()) {
        display_text("Invalid move: Did not move player\n");
        return false;
    }
    else if(end_hex->GetType() == HexagonType::PlayerHex || end_hex->GetType() == HexagonType::MonsterHex) {
        display_text("Invalid move: Hex is occupied\n");
        return false;
    }
    else if(end_hex->GetPassable() == false) {
        display_text("Invalid move: Hex is not passable\n");
        return false;
    }
    
    std::vector<Hexagon*> path = map.PathFind(start_hex, end_hex);
    if(path.size() == 0) {
        display_text("Invalid move: No path to hex\n");
        return false;
    }
    else if((int)path.size() > roll) {
        display_text("Invalid move: Path is longer than roll\n");
        return false;
    }
    else {
        display_text("Valid move\n");
        return true;
    }
}

void move_character(GameMap &map, Character &character, pair<int, int> move) {
    map.ChangeHex(character.GetColumn(), character.GetRow(), HexagonType::BaseHex);
    
    character.SetColumn(move.first);
    character.SetRow(move.second);
    
    map.ChangeHex(move.second, move.first, HexagonType::PlayerHex);
}

int game_loop(GameMap &map, GameCharacters &characters) {
    while(characters.GetNumberCharacters() > 1) {
        for(int i = 0; i < characters.GetNumberCharacters(); i++) {
            Character curr_char = *characters.GetCharacter(i);
            display_text("It is ");
            display_text(curr_char.GetName());
            display_text("'s turn\n\n");

            cout << "x: " << curr_char.GetColumn() << "  y: " << curr_char.GetRow() << endl;
            
            display_text("Enter Dice Roll: ");
            string roll = fetch_input();
            int roll_num = stoi(roll);

            //display possible moves


            display_text("Move Character on Map\n");
            pair<int, int> move = get_move();

            //check if move is valid
            while(!check_valid_move(axial_to_cart(move), roll_num, map, curr_char)) {
                display_text("Move Character again\n");
                move = get_move();
            }

            //move character
            move_character(map, curr_char, axial_to_cart(move));
            cout << "x: " << curr_char.GetColumn() << "  y: " << curr_char.GetRow() << endl;
            map.PrintMap();
            //proceed with game


        }
    }
}