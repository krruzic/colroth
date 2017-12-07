#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <SDL/SDL_video.h>

namespace Engine {
    class Window {
    private:
        int WIDTH = 400;
        int HEIGHT = 240;

    public:
        typedef enum {
            TOP_SCREEN,
            BOTTOM_SCREEN
        } SCREEN;

        Window();

        SDL_Surface *surface;

        void create(SCREEN s);

        SCREEN screen;

        void draw(int offsetX, int offsetY, SDL_Surface *source, SDL_Rect *clip = nullptr);

        void clear();
    };
}
#endif