#pragma once

#include "graphics/Renderer.hpp"

#include <memory>

namespace vulture{
    class SDL2Renderer : public Renderer{
    public:
        virtual void clear() override;
        virtual void present() override;
        virtual void drawingColor(const Color &) override;
    };
}
