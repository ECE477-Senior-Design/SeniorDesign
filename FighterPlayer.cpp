/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/27/2023
*/

#include "FighterPlayer.hh"

//Constructor for fighter class
FighterPlayer::FighterPlayer(int column, int row, 
        int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma,
        int max_health_points, int current_health_points, int armor_class, int initiative, int speed) :
        Character(column, row, 
        strength, dexterity, constitution, intelligence, wisdom, charisma,
        max_health_points, current_health_points, armor_class, initiative, speed) {
    _class = Fighter; //Sets class to fighter
}