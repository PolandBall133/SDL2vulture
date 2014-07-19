#pragma once

#include "graphics/Renderer.hpp"
#include "windows/SDL2Window.hpp"

#include "SDL2/SDL.h"

#include <memory>

namespace vulture{
    class SDL2Renderer : public Renderer{
    public:
        SDL2Renderer(std::weak_ptr<SDL2Window>);
        virtual void clear() override;
        virtual void present() override;
        virtual void drawingColor(const Color &) override;

        virtual const Rectangle viewPort() const override;
        virtual void viewPort(const Rectangle &) override;

        virtual const Vector2 scale() const override;
        virtual void scale(const Vector2 &) override;

        virtual const Size logicalSize() const override;
        virtual void logicalSize(const Size &) override;
    protected:
        typedef std::shared_ptr<SDL_Renderer> renderer_handle;
        renderer_handle _handle;
    };
}
