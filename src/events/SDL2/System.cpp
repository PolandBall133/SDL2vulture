#include "events/SDL2/System.hpp"
#include "events/Event.hpp"
#include <array>
using namespace std;
namespace vulture{
    namespace events{
        namespace SDL2{
            void
            System::poll(){
                SDL_Event sdle;
                events::Event e;
                while(SDL_PollEvent(&sdle)){
                    prepareEvent(e, sdle);
                    handleEvent(e);
                }
            }

            void
            System::prepareEvent(events::Event &e, SDL_Event &sdle){
                if(sdle.type == SDL_WINDOWEVENT)
                    prepareWindowEvent(e, sdle);
            }

            void
            System::prepareWindowEvent(events::Event &e, SDL_Event &sdle){
                using namespace events;
                e.type = events::Event::Type::Window;
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
                static const array<WindowEvent::Type, 8> vulture_types {{
                    WindowEvent::Type::Shown,
                    WindowEvent::Type::Exposed,
                    WindowEvent::Type::Moved,
                    WindowEvent::Type::Resized,
                    WindowEvent::Type::Minimized,
                    WindowEvent::Type::Maximized,
                    WindowEvent::Type::Restored,
                    WindowEvent::Type::Closed
                }};

                for(size_t i = 0; i < sdl2_types.size(); ++i)
                    if(sdle.window.event == sdl2_types[i]){
                        e.events.window.type = vulture_types[i];
                        e.events.window.ID = sdle.window.windowID;
                        return;
                    }
            }
        }
    }
}
