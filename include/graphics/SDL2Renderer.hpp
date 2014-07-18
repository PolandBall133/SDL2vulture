#pragma once

#include "graphics/Renderer.hpp"

#include "SDL2/SDL.h"

#include <memory>

namespace vulture{
    class SDL2Renderer : public Renderer{
    public:
        virtual void clear() override;
        virtual void present() override;
        virtual void drawingColor(const Color &) override;
    protected:
        typedef std::shared_ptr<SDL_Renderer> renderer_handle;
        renderer_handle _handle;
    };
}
