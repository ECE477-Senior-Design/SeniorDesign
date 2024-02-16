#ifndef GAMEFLOW_HH
#define GAMEFLOW_HH

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "utils/utils.hh"
#include "map/GameMap.hh"
#include "character/GameCharacters.hh"

using namespace std;

vector<string> getMapandCharStrings(string filepath);
vector<string> PromptGameStart(void);
void startGame(void);
int game_loop(GameMap &map, GameCharacters &characters);

#endif