/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/27/2023
*/

#ifndef FIGHTERPLAYER_HH
#define FIGHTERPLAYER_HH

#include "BaseCharacter.hh"

//Class definition of a figher class for a player, derived from character class
class FighterPlayer : public Character {
    public:
        FighterPlayer(int column, int row, 
        int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma,
        int max_health_points, int current_health_points, int armor_class, int initiative, int speed); //Constructor for fighter class
};

#endif