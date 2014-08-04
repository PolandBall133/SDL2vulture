#include "windows/SDL2/EventsPoller.hpp"
#include "windows/SDL2/Events.hpp"
#include "SDL2/SDL.h"
#include <list>

using namespace std;
namespace vulture{
    namespace windows{
        namespace SDL2{
            void
            EventsPoller::poll(){
                SDL_Event sdl_event;
                list<SDL_Event> events;
                while(SDL_PollEvent(&sdl_event)){
                    events.push_back(sdl_event);
                    SDL2::Event event(sdl_event);
                    callWindowEventHandler(event, sdl_event.window.windowID);
                }
            }
        }
    }
}
