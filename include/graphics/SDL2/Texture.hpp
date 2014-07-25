#pragma once

#include "graphics/Renderer.hpp"
#include "graphics/Texture.hpp"

#include "SDL2/SDL.h"

#include <memory>
#include <string>

namespace vulture{
    namespace graphics{
        namespace SDL2{
            class Texture : public graphics::Texture<SDL2::Renderer>{
            public:
                virtual void load(SDL2::Renderer &, const std::string &) override;

                virtual void color(const Color &) override;
            protected:
                typedef std::shared_ptr<SDL_Texture> texture_handle;
                texture_handle _handle;
            private:
                typedef graphics::Texture<SDL2::Renderer> base;
            };
        }
    }
}
