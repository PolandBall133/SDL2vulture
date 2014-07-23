#pragma once

#include "SDL2/SDL.h"
#include "Core/TicksProvider.hpp"

namespace vulture{
    namespace core{
        namespace SDL2{
            class TicksProvider : public core::TicksProvider{
            public:
                virtual time_t ticks() override;
            };
        }
    }
}
