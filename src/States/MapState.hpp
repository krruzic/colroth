#ifndef COLROTH_TITLESTATE_HPP
#define COLROTH_TITLESTATE_HPP

#include "../Engine/State.hpp"
#include "SDL/SDL.h"
#include "../Engine/Game.h"
#include "../Engine/Tile.h"
#include "../Engine/ViewPort.h"
#include "../Engine/AnimTile.h"

namespace Colroth {

    class MapState : public Engine::State {
    public:
        MapState(Engine::StateStack &stack, Context &context);

        virtual void renderTopScreen(Engine::Window &window);

        virtual void renderBottomScreen(Engine::Window &window);

        virtual bool update(float delta);

        virtual bool processEvent(const SDL_Event &event);

    private:
        SDL_Surface *dots;
        SDL_Surface *p;
        int posx, posy;
        int playx, playy;
        static const int TILES_X = 9;
        static const int TILES_Y = 10; //50x50 map
        Engine::Tile MAP[TILES_X][TILES_Y] = {
                {3, 3, 0, 3, 3, 3, 3, 3, 3, 3},
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
        };
        Engine::AnimTile player = Engine::AnimTile(0,3);
        Engine::Viewport vp = {Engine::Vector2<int>{0, 0}, Engine::Vector2<int>{416, 256}};
    };

}
#endif
