#include "SDL2TicksProvider.hpp"

namespace vulture{
    time_t
    SDL2TicksProvider::ticks(){
        return SDL_GetTicks();
    }
}
