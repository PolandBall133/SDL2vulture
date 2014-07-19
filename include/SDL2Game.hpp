#pragma once
#include <memory>

#include "SDL2/SDL.h"

#include "Game.hpp"
#include "windows/SDL2Window.hpp"
#include "SDL2TicksProvider.hpp"

namespace vulture{
    class SDL2Game : public Game{
    public:
        SDL2Game();
    protected:
        virtual void initialize() override;
        virtual void finalize() override;
    private:
        void initialize_sdl2();
        void finalize_sdl2();
    };
}
