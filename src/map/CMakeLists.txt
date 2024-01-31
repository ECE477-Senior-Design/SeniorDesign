cmake_minimum_required( VERSION 3.22.0 )

project(DungeonCrawler) #TODO: verify if this is correct

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

set(MAP_SRC
    ./Hexagon.hh
    ./BaseHexagon.hh
    ./BaseHexagon.cpp
    ./GameMap.hh
    ./GameMap.cpp
    ./MonsterHexagon.hh
    ./MonsterHexagon.cpp
    ./PlayerHexagon.hh
    ./PlayerHexagon.cpp
    ./WallHexagon.hh
    ./WallHexagon.cpp)

target_sources(DungeonCrawler PRIVATE ${MAP_SRC})