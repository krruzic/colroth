#include "Colroth.h"

namespace Colroth {
    Colroth::Colroth() : m_stateStack(Engine::State::Context(m_name, m_fs)) {
        m_stateStack.registerState<MapState>(States::Title);
        m_stateStack.pushState(States::Title);
    }

    Colroth::~Colroth() {

    }

    void Colroth::update(float delta) {
        // Need to update before checking if empty
        m_stateStack.update(delta);
        if (m_stateStack.isEmpty())
            exit();

    }

    void Colroth::processEvent(SDL_Event &event) {
        m_stateStack.processEvent(event);
        switch (event.type) {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_RETURN) {
                    exit();
                }
                break;
        }
    }

    void Colroth::renderTopScreen(Engine::Window &window) {
        m_stateStack.renderTopScreen(window);
    }

    void Colroth::renderBottomScreen(Engine::Window &window) {
        m_stateStack.renderBottomScreen(window);
    }
}