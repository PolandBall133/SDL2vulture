#pragma once

#include "graphics/Renderer.hpp"
#include "graphics/Texture.hpp"

#include "SDL2/SDL.h"

#include <memory>
#include <string>

namespace vulture{
    namespace graphics{
        namespace SDL2{
            class Texture : public graphics::Texture{
            public:
                virtual void load(graphics::Renderer &, const std::string &) override;

                virtual void color(const Color &) override;
            protected:
                typedef std::shared_ptr<SDL_Texture> texture_handle;
                texture_handle _handle;
            };
        }
    }
}
