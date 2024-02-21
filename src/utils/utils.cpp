#include "utils.hh"

void display_text(std::string text) {
    std::cout << text;
}

std::string fetch_input(void) {
    std::string input;
    std::cin >> input;
    return input;
}

std::pair<int, int> get_move(void) {
    display_text("Move Character: \n");
    display_text("column: ");
    std::string col = fetch_input();
    int col_num = std::stoi(col);
    display_text("row: ");
    std::string row = fetch_input();
    int row_num = std::stoi(row);
    
    return std::make_pair(col_num, row_num);
}