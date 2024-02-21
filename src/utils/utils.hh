#ifndef UTILS_HH
#define UTILS_HH

#include <iostream>
#include <string>


//this acts as a placeholder and will be replaced with LCD communication later
void display_text(std::string text);
std::string fetch_input(void);
std::pair<int, int> get_move(void);

#endif