#include "SDL2Window.hpp"

namespace vulture{
    SDL2TicksProvider::ticks(){
        return SDL_GetTicks();
    }
}
