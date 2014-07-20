#pragma once

#include "windows/WindowEventsPoller.hpp"

namespace vulture{
    class SDL2WindowEventsPoller : public WindowEventsPoller{
    public:
        virtual void pollEvents() override;
    };
}
