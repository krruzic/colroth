//
// Created by krruzic on 11/28/17.
//

#include "AnimTile.h"

namespace Engine {
    AnimTile::AnimTile(int t, int f) : Tile(t) {
        Tile::tile = static_cast<TileProps>(t);
        frames = f;
        mRenderRect.w = WIDTH;
        mRenderRect.h = HEIGHT;
        mRenderRect.x = Tile::tile * 32;
        mRenderRect.y = 0;
        startX = mRenderRect.x;
        mRenderRect.y = 0;
    }

    void AnimTile::set_direction(int d) {
        dir = static_cast<direction>(d);
        if (dir == DOWN)
            mRenderRect.y = 0;
        if (dir == LEFT)
            mRenderRect.y = 32;
        if (dir == RIGHT)
            mRenderRect.y = 64;
        if (dir == UP)
            mRenderRect.y = 96;
    }

    void AnimTile::render(int x, int y, Window *w) {
        if (!paused) {
            if (counter == 10) {
                curFrame++;
                mRenderRect.x += 32;
            }
            if (curFrame == frames) {
                curFrame = 0;
                mRenderRect.x = startX;
            }
            if (counter > 10)
                counter = 0;
        }
        w->draw(x, y, surface, &mRenderRect);
        counter++;
    }

    void AnimTile::set_surface(SDL_Surface *s) {
        Tile::set_surface(s);
    }

    void AnimTile::play() {
        paused = false;
    }

    void AnimTile::pause() {
        paused = true;
        curFrame = 0;
    }
}
