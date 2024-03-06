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
    display_text("row: ");
    std::string row = fetch_input();
    int row_num = std::stoi(row);
    display_text("column: ");
    std::string col = fetch_input();
    int col_num = std::stoi(col);
    
    return std::make_pair(col_num, row_num);
}

std::pair<int, int> cart_to_axial(std::pair<int,int> coords) {
    int r = coords.first;
    int q = r - std::floor(coords.second / 2);
    return std::make_pair(q, r);
}

std::pair<int, int> axial_to_cart(std::pair<int,int> coords) {
    std::cout << coords.second << std::endl;
    int y = coords.first;
    int x = coords.second + std::floor(coords.first / 2);
    return std::make_pair(x,y);
}