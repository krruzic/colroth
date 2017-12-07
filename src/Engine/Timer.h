#ifndef ENGINE_TIMER_H
#define ENGINE_TIMER_H

#include "SDL/SDL.h"
#include "Timer.h"

namespace Engine {

    class Timer {
    private:
        //The clock time when the timer started
        int startTicks;

        //The ticks stored when the timer was paused
        int pausedTicks;

        //The timer status
        bool paused;
        bool started;

    public:
        //Initializes variables
        Timer();

        //The various clock actions
        void start();

        void stop();

        void pause();

        void unpause();

        //Gets the timer's time
        int get_ticks();

        //Checks the status of the timer
        bool is_started();

        bool is_paused();
    };
}
#endif //ENGINE_TIMER_H
