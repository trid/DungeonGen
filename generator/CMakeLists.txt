cmake_minimum_required(VERSION 3.5)
project(generator)

set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE_FILES *.cpp)

add_definitions(-DSFML_STATIC)

add_executable(DunGen ${SOURCE_FILES} Tile.cpp Tile.h RandomRoomGenerator.cpp RandomRoomGenerator.h)
target_link_libraries(DunGen sfml-graphics)
target_link_libraries(DunGen sfml-window)
target_link_libraries(DunGen sfml-system)
target_link_libraries(DunGen sfml-main)