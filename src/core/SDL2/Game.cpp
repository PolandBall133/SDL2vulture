#include "core/SDL2/Game.hpp"

namespace vulture{
    namespace core{
        namespace SDL2{
            Game::Game():
                core::Game(new windows::SDL2::Window::Factory(), new core::SDL2::TicksProvider())
            {}

            void
            Game::initialize(){
                initialize_sdl2();
                core::Game::initialize();
            }

            void
            Game::finalize(){
                finalize_sdl2();
                core::Game::finalize();
            }

            void
            Game::initialize_sdl2(){
                SDL_Init(SDL_INIT_EVERYTHING);
                SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
            }

            void
            Game::finalize_sdl2(){
                SDL_Quit();
            }
        }
    }
}
