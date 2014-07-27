#pragma once

#include "graphics/SpriteBatch.hpp"
#include "graphics/SDL2/Renderer.hpp"

#include "SDL2/SDL.h"

#include <memory>

namespace vulture{
    namespace graphics{
        namespace SDL2{
            class SpriteBatch : public graphics::SpriteBatch{
                typedef graphics::SpriteBatch base;
            protected:
                struct Drawer : public base::Drawer{};
                typedef std::weak_ptr<SDL2::Renderer> renderer_handle;
                renderer_handle _renderer_handle;
            public:
                SpriteBatch(renderer_handle);
                virtual void begin() override;
                virtual void end() override;

                virtual const Color backgroundColor() const override;
                virtual void backgroundColor(const Color &) override;
            };
        }
    }
}
