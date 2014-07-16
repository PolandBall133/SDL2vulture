#pragma once

#include "SDL2/SDL.h"
#include "TicksProvider.hpp"

namespace vulture{
    class SDL2TicksProvider : public TicksProvider{
    public:
        virtual time_t ticks() override;
    };
}
