#ifndef UTILS_HH
#define UTILS_HH

#include <iostream>
#include <string>
#include <cmath>


//this acts as a placeholder and will be replaced with LCD communication later
void display_text(std::string text);
std::string fetch_input(void);
std::pair<int, int> get_move(void);
std::pair<int, int> cart_to_axial(std::pair<int,int> coords);
std::pair<int, int> axial_to_cart(std::pair<int,int> coords);

#endif