cmake_minimum_required(VERSION 3.8)
project(colroth)
set(CMAKE_CXX_STANDARD 11)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
set(SOURCE_FILES
        src/Engine/State.cpp src/States/StateIdentifiers.hpp src/Engine/StateStack.cpp src/States/MapState.hpp src/States/MapState.cpp
        src/main.cpp src/Colroth.cpp src/Colroth.h
        src/Engine/Window.cpp src/Engine/Window.h src/Engine/Game.cpp
        src/Engine/Game.h src/Engine/Timer.cpp src/Engine/Timer.h src/Engine/MapLoader.cpp
        src/Engine/MapLoader.h src/Engine/FS.cpp src/Engine/FS.h src/Engine/Tile.cpp src/Engine/Tile.h src/Engine/ViewPort.h src/Engine/AnimTile.cpp src/Engine/AnimTile.h src/Engine/Sprite.cpp src/Engine/Sprite.h)
add_executable(${PROJECT_NAME}-emu ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME}-emu PROPERTIES COMPILE_DEFINITIONS EMULATION=1)
target_link_libraries(${PROJECT_NAME}-emu SDL_mixer SDL_ttf freetype
        bz2 mikmod mad ogg SDL_image SDL png jpeg z m )

#remove_definitions(-DEMULATION)
add_custom_target(
        ${PROJECT_NAME}
        COMMAND ./makefile.sh
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS EMULATION=0)
message(WARNING "Build type: ${CMAKE_BUILD_}")