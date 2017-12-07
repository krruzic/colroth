#ifndef ENGINE_FS_H
#define ENGINE_FS_H

#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

namespace Engine {
    class FS {
    public:
        std::string get_name(std::string fn);

        SDL_Surface *load_image(std::string fn);

    private:
        const std::string ROMFS = "romfs:/";
        const std::string EMU = "../data/";
    };
}

#endif //ENGINE_FS_H
