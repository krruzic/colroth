#ifndef ENGINE_TILE_H
#define ENGINE_TILE_H

#include <SDL/SDL_video.h>
#include <string>
#include "FS.h"
#include "Window.h"

namespace Engine {
    class Tile {
    public:
        enum TileProps {
            NOTHING, WALL, XD, YD, PLAYER
        };
        static const int WIDTH = 32;
        static const int HEIGHT = 32;
        static std::string data;
        TileProps tile; // Which tile is this?
        SDL_Surface* surface;
        SDL_Rect mRenderRect;

    public:
        Tile(int t);
        void render(int x, int y, Window *w);

        void set_surface(SDL_Surface *s);
    };
}


#endif
