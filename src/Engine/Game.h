#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#ifndef EMULATION
#include "3ds.h"
#endif

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Window.h"
#include <string>
#include <cstdio>
#include <ctime>
#include "Timer.h"

namespace Engine {
    class Game {
    public:
        virtual void processEvent(SDL_Event &event) = 0;

        virtual void update(float delta) = 0;

        virtual void renderTopScreen(Window &window) = 0;

        virtual void renderBottomScreen(Window &window) = 0;

        Timer fps;

        void run();

        void exit();

        Game();

    protected:
        Window windowTop, windowBottom;
        SDL_Surface *display = nullptr;
    private:
        bool m_triggerExit = false;
        SDL_Rect BTM_OFFSET = {0, 240};

        void render();
    };
}
#endif