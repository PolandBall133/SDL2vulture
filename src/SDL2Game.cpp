#include "SDL2Game.hpp"

namespace vulture{
    SDL2Game::SDL2Game():
        Game(new SDL2Window::Factory(), new SDL2TicksProvider())
    {}
}
