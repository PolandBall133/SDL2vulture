#include "windows/SDL2WindowEventsPoller.hpp"
#include "SDL2/SDL.h"

namespace vulture{
    void
    SDL2WindowEventsPoller::pollEvents(){
        SDL_Event e;
        while(SDL_PollEvent(&e)){

        }
    }
}
