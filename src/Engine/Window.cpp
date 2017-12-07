#include "Window.h"

namespace Engine {
    Window::Window() {}

    void Window::create(SCREEN s) {
        screen = s;
        SDL_Surface* tmp = SDL_GetVideoSurface();
        surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 8, 0, 0, 0, 0);
        SDL_SetColors(surface, tmp->format->palette->colors, 0, tmp->format->palette->ncolors);
    }

    void Window::draw(int offsetX, int offsetY, SDL_Surface *source, SDL_Rect *clip) {
        SDL_Rect offset = {offsetX, offsetY};
        SDL_BlitSurface(source, clip, surface, &offset);
    }

    void Window::clear() {
        SDL_FillRect(surface, &surface->clip_rect, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    }

}