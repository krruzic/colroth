#include <fstream>
#include "FS.h"

namespace Engine {
    std::string FS::get_name(std::string fn) {
        #ifndef EMULATION
        fn.insert(0,ROMFS);
        return fn;
        #else
        fn.insert(0, EMU);
        return fn;
        #endif
    }

    SDL_Surface *FS::load_image(std::string fn) {
        //The image that's loaded
        SDL_Surface *loadedImage = NULL;
        SDL_Surface *optimizedImage = NULL;
        loadedImage = IMG_Load(get_name(fn).c_str());
        if (loadedImage != NULL) {
            //Create an optimized surface
            optimizedImage = SDL_DisplayFormat(loadedImage);
            //Free the old surface
            SDL_FreeSurface(loadedImage);
            //If the surface was optimized
            if (optimizedImage != NULL) {
                //Color key surface
                SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF));
            }
        }
        return optimizedImage;
    };


    void getFile(std::string filename, /*out*/ std::ifstream &file) {
        std::ofstream dummy(filename.c_str());
        if (!dummy.is_open()) {
            return;
        }
        file.open(filename.c_str());
    }
}