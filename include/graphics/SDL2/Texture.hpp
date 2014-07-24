#pragma once

#include "graphics/SDL2/Renderer.hpp"

#include "SDL2/SDL.h"

#include <memory>
#include <string>

namespace vulture{
    namespace graphics{
        namespace SDL2{
            class Texture : public vulture::Texture{
            public:
                virtual void load(SDL2::Renderer &, const std::string &) override;

                virtual const Color &color() const override;
                virtual void color(const Color &) override;
            };
        }
    }
}
