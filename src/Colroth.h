#ifndef COLROTH_COLROTH_H
#define COLROTH_COLROTH_H

#include "Engine/Game.h"
#include "Engine/StateStack.hpp"
#include "Engine/Window.h"
#include "States/MapState.hpp"
#include <string>

namespace Colroth {
    class Colroth : public Engine::Game {
    public:
        Colroth();

        ~Colroth();

        void update(float delta);

        void processEvent(SDL_Event &event);

        void renderTopScreen(Engine::Window &window);

        void renderBottomScreen(Engine::Window &window);

    private:
        Engine::StateStack m_stateStack;

        // Shared State context variables
        std::string m_name;
        Engine::FS m_fs;
//        SDL_Color m_color;
//            TextureManager m_texmgr;
    };
}
#endif
