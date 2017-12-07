#include "State.hpp"
#include "StateStack.hpp"

namespace Engine {


    State::Context::Context(std::string &name, Engine::FS &fs)
            : name(name), fs(fs) {
    }

    State::State(StateStack &stack, Context &context)
            : m_stack(&stack), m_context(context) {
    }

    State::~State() {
    }

    void State::requestStackPush(Colroth::States::ID stateID) {
        m_stack->pushState(stateID);
    }

    void State::requestStackPop() {
        Colroth::States::ID s = m_stack->getTopID();
        m_stack->popState();
    }

    void State::requestStackClear() {
        m_stack->clearStates();
    }

    State::Context State::getContext() const {
        return m_context;
    }

}
