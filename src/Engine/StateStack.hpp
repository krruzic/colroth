#ifndef ENGINE_STATESTACK_HPP
#define ENGINE_STATESTACK_HPP

#include "State.hpp"
#include "../States/StateIdentifiers.hpp"
#include "SDL/SDL.h"

#include <vector>
#include <utility>
#include <functional>
#include <map>


namespace Engine {

    class StateStack {
    public:
        enum Action {
            Push,
            Pop,
            Clear,
        };

    public:
        explicit StateStack(State::Context context);

        template<typename T>
        void registerState(Colroth::States::ID stateID);

        void update(float delta);

        void renderTopScreen(Engine::Window &window);

        void renderBottomScreen(Engine::Window &window);

        void processEvent(const SDL_Event &event);

        void pushState(Colroth::States::ID stateID);

        void popState();

        void clearStates();

        bool isEmpty() const;

        int getSize();

    public:
        Colroth::States::ID getTopID();

    private:
        State::Ptr createState(Colroth::States::ID stateID);

        void applyPendingChanges();


        struct PendingChange {
            explicit PendingChange(Action action, Colroth::States::ID stateID = Colroth::States::None);

            Action action;
            Colroth::States::ID stateID;
        };

        struct StateStackItem {
            Colroth::States::ID id;
            State::Ptr pointer;
        };

        std::vector<StateStackItem> m_stack;
        std::vector<PendingChange> m_pendingList;

        State::Context m_context;
        std::map<Colroth::States::ID, std::function<State::Ptr()>> m_factories;

    };


    template<typename T>
    void StateStack::registerState(Colroth::States::ID stateID) {
        m_factories[stateID] = [this]() {
            return State::Ptr(new T(*this, m_context));
        };
    }

} // namespace COLROTH

#endif // ENGINE_STATESTACK_HPP
