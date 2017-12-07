#include "Tile.h"

namespace Engine {
    Tile::Tile(int t) {
        Tile::tile = static_cast<TileProps>(t);
        mRenderRect.w = WIDTH;
        mRenderRect.h = HEIGHT;
        mRenderRect.x = Tile::tile * 32;
        mRenderRect.y = 0;
    }

    void Tile::render(int x, int y, Window *w) {
        w->draw(x, y, surface, &mRenderRect);
    }

    void Tile::set_surface(SDL_Surface* s) {
        surface = s;
    }
};