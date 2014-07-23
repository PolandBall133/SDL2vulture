#pragma once

#include "windows/EventsPoller.hpp"

namespace vulture{
    namespace windows{
        namespace SDL2{
            class EventsPoller : public windows::EventsPoller{
            public:
                virtual void poll() override;
            };
        }
    }
}
