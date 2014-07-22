#include "windows/SDL2WindowEvents.hpp"
#include "SDL2/SDL.h"

#include <array>
using namespace std;

namespace vulture{

    SDL2WindowEvent::SDL2WindowEvent(SDL_Event &e){
        static const array<uint32_t, 8> sdl2_types = {
            SDL_WINDOWEVENT_SHOWN,
            SDL_WINDOWEVENT_EXPOSED,
            SDL_WINDOWEVENT_MOVED,
            SDL_WINDOWEVENT_RESIZED,
            SDL_WINDOWEVENT_MINIMIZED,
            SDL_WINDOWEVENT_MAXIMIZED,
            SDL_WINDOWEVENT_RESTORED,
            SDL_WINDOWEVENT_CLOSE
        };
        static const array<WindowEvent::Type, 8> vulture_types = {
            WindowEvent::Type::Shown,
            WindowEvent::Type::Exposed,
            WindowEvent::Type::Moved,
            WindowEvent::Type::Resized,
            WindowEvent::Type::Minimized,
            WindowEvent::Type::Maximized,
            WindowEvent::Type::Restored,
            WindowEvent::Type::Closed
        };
        if(e.type != SDL_WINDOWEVENT)
            return;

        for(size_t i = 0; i < sdl2_types.size(); ++i)
            if(e.window.event == sdl2_types[i]){
                _type = vulture_types[i];
                return;
            }
    }
}
