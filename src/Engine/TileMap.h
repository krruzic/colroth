#ifndef COLROTH_TILEMAP_H
#define COLROTH_TILEMAP_H

#include <SDL/SDL_video.h>
#include "Tile.h"

namespace Engine {
    class TileMap {
    private:
        SDL_Surface* tileset;
        void set_tileset(SDL_Surface* ts);
        SDL_Surface* get_tileset();

//        vector< vector<static Tile::tile> > tilemap;
    };
}

#endif
