#include "windows/SDL2/EventsPoller.hpp"
#include "windows/SDL2/Events.hpp"
#include "SDL2/SDL.h"

namespace vulture{
    namespace windows{
        namespace SDL2{
            void
            EventsPoller::poll(){
                SDL_Event sdl_event;
                while(SDL_PollEvent(&sdl_event)){
                    SDL2::Event event(sdl_event);
                    callWindowEventHandler(event, sdl_event.window.windowID);
                }
            }
        }
    }
}
