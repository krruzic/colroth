#include "MapState.hpp"

namespace Colroth {

    MapState::MapState(Engine::StateStack &stack, Context &context)
            : State(stack, context) {
        posx = 0;
        posy = 0;
        playx = 0;
        playy = 0;

        dots = context.fs.load_image("tilemap.png");
        p = context.fs.load_image("char.png");
        player.set_surface(p);

        for (int x = 0; x < TILES_X; ++x) {
            for (int y = 0; y < TILES_Y; ++y) {
                MAP[x][y].set_surface(dots);
            }
        }
    }

    void MapState::renderTopScreen(Engine::Window &window) {
        window.clear();
        int posX, posY;
        for (int x = 0; x < TILES_X; ++x) {
            for (int y = 0; y < TILES_Y; ++y) {
                posX = x * 32;
                posY = y * 32;
                if ((posX + Engine::Tile::WIDTH > vp.position.x &&
                     posX - Engine::Tile::WIDTH < vp.position.x + vp.size.x) &&
                    (posY + Engine::Tile::HEIGHT > vp.position.y &&
                     posY - Engine::Tile::HEIGHT < vp.position.y + vp.size.y)) // check if the Tile is currently visible
                    MAP[x][y].render(posX - vp.position.x, posY - vp.position.y, &window);
            }
        }
        player.render(playx, playy, &window);
    }

    void MapState::renderBottomScreen(Engine::Window &window) {

    }

    bool MapState::update(float delta) {
        return true;
    }

    bool MapState::processEvent(const SDL_Event &event) {
        if (event.type == SDL_KEYDOWN) {
            player.play();
            if (event.key.keysym.sym == SDLK_DOWN) {
                player.set_direction(0);
                playy += 32;
            } else if (event.key.keysym.sym == SDLK_UP) {
                player.set_direction(3);
                if (playy > 0)
                    playy -= 32;
            } else if (event.key.keysym.sym == SDLK_LEFT) {
                player.set_direction(1);
                if (playx > 0)
                    playx -= 32;
            } else if (event.key.keysym.sym == SDLK_RIGHT) {
                player.set_direction(2);
                playx += 32;
            }
            if (event.key.keysym.sym == SDLK_l) {
                playy = 0;
                playx = 0;
                vp.position.x = 0;
                vp.position.y = 0;
            }
        }
        if (playy >= 32 * 7) {
            playy -= 32;
            vp.position.y += 32;
        } else if (playy <= 0) {
            playy += 32;
            vp.position.y -= 32;
        }
        return true;
    }
}
