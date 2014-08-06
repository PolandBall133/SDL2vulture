#include "windows/SDL2/Events.hpp"
#include "SDL2/SDL.h"

#include <array>
using namespace std;

namespace vulture{
    namespace windows{
        namespace SDL2{
            Event::Event(SDL_Event &e){
                static const array<uint32_t, 8> sdl2_types{{
                    SDL_WINDOWEVENT_SHOWN,
                    SDL_WINDOWEVENT_EXPOSED,
                    SDL_WINDOWEVENT_MOVED,
                    SDL_WINDOWEVENT_RESIZED,
                    SDL_WINDOWEVENT_MINIMIZED,
                    SDL_WINDOWEVENT_MAXIMIZED,
                    SDL_WINDOWEVENT_RESTORED,
                    SDL_WINDOWEVENT_CLOSE
                }};
                static const array<windows::Event::Type, 8> vulture_types {{
                    windows::Event::Type::Shown,
                    windows::Event::Type::Exposed,
                    windows::Event::Type::Moved,
                    windows::Event::Type::Resized,
                    windows::Event::Type::Minimized,
                    windows::Event::Type::Maximized,
                    windows::Event::Type::Restored,
                    windows::Event::Type::Closed
                }};
                if(e.type != SDL_WINDOWEVENT)
                    return;

                for(size_t i = 0; i < sdl2_types.size(); ++i)
                    if(e.window.event == sdl2_types[i]){
                        _type = vulture_types[i];
                        return;
                    }
            }
        }
    }
}
