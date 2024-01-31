cmake_minimum_required( VERSION 3.22.0 )

project(DungeonCrawler)#TODO: Verify if this is the correct name

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

set(CHARACTER_SRC
    ./Character.hh
    ./BaseCharacter.hh
    ./BaseCharacter.cpp
    ./GameCharacter.hh
    ./GameCharacter.cpp
    ./MonsterFighter.hh
    ./MonsterFighter.cpp
    ./PlayerFighter.hh
    ./PlayerFighter.cpp)

target_sources(DungeonCrawler PRIVATE ${CHARACTER_SRC})