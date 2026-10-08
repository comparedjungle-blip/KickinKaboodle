cmake_minimum_required(VERSION 3.10)
project(KickinKaboodle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find raylib
find_package(raylib QUIET)

if (NOT raylib_FOUND)
  # If raylib is not found, you can add it as a subdirectory or build it
  message(STATUS "raylib not found, consider installing it via brew or building from source")
endif()

# Source files
set(SOURCES
  main.cpp
  AnimationSystem.cpp
  BattleScene.cpp
  Enemy.cpp
  Globals.cpp
  MainScene.cpp
  MenuObjects.cpp
  Player.cpp
  ShopScene.cpp
  Structs.cpp
  TileMapping.cpp
  mechanics.cpp
  room.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link raylib
if(raylib_FOUND)
  target_link_libraries(${PROJECT_NAME} raylib)
else()
  message(FATAL_ERROR "raylib is required but not found. Install it or add it as a subdirectory.")
endif()

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})