#include "SDL2Game.hpp"

namespace vulture{
    SDL2Game::SDL2Game():
        Game(new SDL2Window::Factory(), new SDL2TicksProvider())
    {}

    void
    SDL2Game::initialize(){
        initialize_sdl2();
        Game::initialize();
    }

    void
    SDL2Game::finalize(){
        finalize_sdl2();
        Game::finalize();
    }

    void
    SDL2Game::initialize_sdl2(){
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    }

    void
    SDL2Game::finalize_sdl2(){
        SDL_Quit();
    }
}
