#pragma once

#include "events/System.hpp"
#include "events/Event.hpp"

#include "SDL2/SDL.h"

#include <memory>

namespace vulture{
    namespace events{
        namespace SDL2{
            class System:
                public events::System{
            public:
                virtual void poll() override;
            protected:
                void prepareEvent(events::Event &, SDL_Event &);
                void prepareWindowEvent(events::Event &, SDL_Event &);
            };
        }
    }
}
