cmake_minimum_required( VERSION 3.22.0 )

project(DungeonCrawler)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

#add_subdirectory(src)
#add_subdirectory(test)

include_directories( ./include ./src )
include(CTest)

set(MAIN
    src/main.cpp)

set(SOURCES 
    src/character/Character.hh
    src/character/BaseCharacter.hh
    src/character/BaseCharacter.cpp
    src/character/GameCharacters.hh
    src/character/GameCharacters.cpp
    src/character/MonsterFighter.hh
    src/character/MonsterFighter.cpp
    src/character/PlayerFighter.hh
    src/character/PlayerFighter.cpp
    src/map/Hexagon.hh
    src/map/BaseHexagon.hh
    src/map/BaseHexagon.cpp
    src/map/GameMap.hh
    src/map/GameMap.cpp
    src/map/MonsterHexagon.hh
    src/map/MonsterHexagon.cpp
    src/map/PlayerHexagon.hh
    src/map/PlayerHexagon.cpp
    src/map/WallHexagon.hh
    src/map/WallHexagon.cpp)



# if external libraries are used, add them here

# Set system name macro
if(UNIX)
    add_definitions(-DSYSTEMNAMEMACRO="Linux")
elseif(WIN32)
    add_definitions(-DSYSTEMNAMEMACRO="Windows")
elseif(APPLE)
    add_definitions(-DSYSTEMNAMEMACRO="Apple MacOS")
endif()

# Disable in-source builds to prevent source tree corruption.
# Common practice -- see openCV CMake
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

enable_testing()

add_executable(dungeon_crawler ${MAIN} ${SOURCES})
add_executable(char_test test/test_character.cpp ${SOURCES})
add_executable(map_test test/test_map.cpp ${SOURCES})

add_custom_target(run
    COMMAND dungeon_crawler
    DEPENDS dungeon_crawler
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_test(NAME char_test COMMAND $<TARGET_FILE:char_test>)
add_test(NAME map_test COMMAND $<TARGET_FILE:map_test>)