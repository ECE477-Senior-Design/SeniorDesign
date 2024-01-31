cmake_minimum_required( VERSION 3.22.0 )

project(DungeonCrawler)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/character)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/map)

set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)


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

add_executable(dungeon_crawler ${SOURCES})