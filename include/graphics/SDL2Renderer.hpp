#pragma once

#include "graphics/Renderer.hpp"

namespace vulture{
    class SDL2Renderer : Renderer{
        virtual void clear() override;
        virtual void present() override;
        virtual void drawingColor() override;
    };
}
