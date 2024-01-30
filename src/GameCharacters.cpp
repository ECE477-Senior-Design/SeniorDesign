/*
MOST RECENT AUTHOR: JACKSON
DATE: 10/27/2023
*/

#include "GameCharacters.hh"

//Constructor of characters vector
GameCharacters::GameCharacters(int number_characters) : _number_characters(number_characters) {
    characters.resize(number_characters, nullptr);
}

//Returns number of characters
int GameCharacters::GetNumberCharacters(void) {
    return _number_characters;
}

//Adds character to character vector
void GameCharacters::AddCharacter(int index, int column, int row, 
        int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma,
        int max_health_points, int current_health_points, int armor_class, int initiative, int speed, CharacterType character_type, Class class_) {
    Character* character = new Character(column, row, 
        strength, dexterity, constitution, intelligence, wisdom, charisma,
        max_health_points, current_health_points, armor_class, initiative, speed);
    character->SetClass(class_); //Sets class of character 
    character->SetCharacterType(character_type); //Sets character type
    characters[index] = character; //Adds character to characters vector
}

//Returns character at index
Character* GameCharacters::GetCharacter(int index) {
    return characters.at(index);
}

//Destructor for characters vector
GameCharacters::~GameCharacters() {
    //Deletes each character in characters vector
    for (int i = 0; i < _number_characters; i++) {
        if (characters[i] != nullptr) {
            delete characters[i];
        }
    }
}