#ifndef ENGINE_STATE_HPP
#define ENGINE_STATE_HPP

#include "../States/StateIdentifiers.hpp"
#include "SDL/SDL.h"
#include "Window.h"
#include "Game.h"
#include "FS.h"
#include <memory>
#include <vector>

namespace Engine {

    class StateStack;

    class State {
    public:
        typedef std::unique_ptr<State> Ptr;

        struct TransitionData {
            std::string message;
            Colroth::States::ID nextStateID;
        };
        struct SurfaceContainer {
            SDL_Surface *surface;
            SDL_Rect rect;
        };

        struct Context {
            Context(std::string &name, Engine::FS &fs);
            std::string &name;
            Engine::FS &fs;
        };

        State(StateStack &stack, Context &context);

        virtual ~State();

        virtual void renderTopScreen(Engine::Window &window) = 0;

        virtual void renderBottomScreen(Engine::Window &window) = 0;

        virtual bool update(float delta) = 0;

        virtual bool processEvent(const SDL_Event &event) = 0;


    protected:
        void requestStackPush(Colroth::States::ID stateID);

        void requestStackPop();

        void requestStackClear();

        Context getContext() const;

    private:
        StateStack *m_stack;
        Context m_context;
    };

}
#endif
