/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/27/2023
*/

#ifndef GAMECHARACTERS_HH
#define GAMECHARACTERS_HH

#include <vector>
#include "BaseCharacter.hh"

//Class for both player and monster characters
class GameCharacters {
    protected:
        int _number_characters; //Number of characters in characters vector
        std::vector<Character> characters; //Characters vector

    public:
        GameCharacters(int number_characters); //Constructor of characters vector
        GameCharacters(std::vector<std::string> input_strlist); //Constructor of characters vector from string

        int GetNumberCharacters(void); //Returns number of characters
        void AddCharacter(int index, std::string name, int column, int row,
        int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma,
        int max_health_points, int current_health_points, int armor_class, int initiative, int speed, CharacterType character_type, Class class_); //Adds character to character vector
        Character& GetCharacter(int index); //Returns character at index
        ~GameCharacters(); //Destructor for characters vector
};

#endif