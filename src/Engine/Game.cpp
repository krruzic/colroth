#include "Game.h"

#define FRAMES_PER_SECOND 60

namespace Engine {

    Game::Game() {

        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK);
        #ifndef EMULATION
        romfsInit();
        #endif
        #ifndef EMULATION
        display = SDL_SetVideoMode(400, 480, 8, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DUALSCR | SDL_DOUBLEBUF);
        #else
        display = SDL_SetVideoMode(400, 480, 8, SDL_HWSURFACE | SDL_DOUBLEBUF);
        #endif

        windowTop.create(Window::TOP_SCREEN);
        windowBottom.create(Window::BOTTOM_SCREEN);
    }


    void Game::render() {
        renderTopScreen(windowTop);
        renderBottomScreen(windowBottom);

        SDL_BlitSurface(windowTop.surface, NULL, display, NULL);
        SDL_BlitSurface(windowBottom.surface, NULL, display, &BTM_OFFSET);

        if (SDL_Flip(display) == -1) {
            m_triggerExit = true;
        }
    }

    void Game::run() {
        SDL_Event event;
        time_t t;
        srand((unsigned) time(&t)); // should only be called once

        #ifndef EMULATION
        while (aptMainLoop()) {
        #else
        while (true) {
        #endif

            while (SDL_PollEvent(&event)) {
                processEvent(event);
                break;
            }

            if (m_triggerExit)
                break;
            if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND) {
                //Sleep the remaining frame time
                SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
            }
            update(fps.get_ticks());

            render();
        }
    }

    void Game::exit() {
        m_triggerExit = true;
        SDL_Quit();
    }
}