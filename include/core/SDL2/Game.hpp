#pragma once
#include <memory>

#include "SDL2/SDL.h"

#include "core/Game.hpp"
#include "windows/SDL2/Window.hpp"
#include "core/SDL2/TicksProvider.hpp"

namespace vulture{
    namespace core{
        namespace SDL2{
            class Game : public core::Game{
            public:
                Game();
            protected:
                virtual void initialize() override;
                virtual void finalize() override;
            private:
                void initialize_sdl2();
                void finalize_sdl2();
            };
        }
    }
}
