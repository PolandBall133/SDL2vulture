#pragma once
#include <memory>

#include "SDL2/SDL.h"

#include "Game.hpp"
#include "SDL2Window.hpp"

namespace vulture{
    class SDL2Game : public Game{
    public:
        SDL2Game();
    };
}
