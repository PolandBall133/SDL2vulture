#include "windows/SDL2WindowEventsPoller.hpp"
#include "windows/SDL2WindowEvents.hpp"
#include "SDL2/SDL.h"

namespace vulture{
    void
    SDL2WindowEventsPoller::pollEvents(){
        SDL_Event sdl_event;
        while(SDL_PollEvent(&sdl_event)){
            SDL2WindowEvent event(sdl_event);
            callWindowEvent(event, /*TODO: get id of a window from SDL_Event*; time to go to sleep*/);
        }
    }
}
