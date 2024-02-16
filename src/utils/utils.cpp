#include "utils.hh"

void display_text(std::string text) {
    std::cout << text;
}

std::string fetch_input(void) {
    std::string input;
    std::cin >> input;
    return input;
}