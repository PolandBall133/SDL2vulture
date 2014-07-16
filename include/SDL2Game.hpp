#pragma once
#include <memory>

#include "SDL2/SDL.h"

#include "Game.hpp"
#include "SDL2Window.hpp"
#include "SDL2TicksProvider.hpp"

namespace vulture{
    class SDL2Game : public Game{
    public:
        SDL2Game();
    };
}
