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
            public:
                SpriteBatch(std::weak_ptr<SDL2::Renderer>);
                virtual void begin() override;
                virtual void end() override;
            };
        }
    }
}
