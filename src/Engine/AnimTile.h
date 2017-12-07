//
// Created by krruzic on 11/28/17.
//

#ifndef COLROTH_ANIMTILE_H
#define COLROTH_ANIMTILE_H

#include "Tile.h"

namespace Engine {

    class AnimTile : Tile {
    public:
        typedef enum {
            DOWN,
            LEFT,
            RIGHT,
            UP
        } direction;
        int frames;
        int curFrame = 0;
        int counter = 0;
        int startX = 0;
        bool paused = true;
        AnimTile(int t, int f);

        void render(int x, int y, Window *w);
        void set_surface(SDL_Surface *s);
        void set_direction(int d);
        void play();
        void pause();
        direction dir;
    };
}

#endif //COLROTH_ANIMTILE_H
