#pragma once

#include "graphics/Renderer.hpp"
#include "graphics/Texture.hpp"

#include "SDL2/SDL.h"

#include <memory>
#include <string>
#include <set>

namespace vulture{
    namespace graphics{
        namespace SDL2{
            class Texture : public graphics::Texture<SDL2::Renderer>{
            public:
                Texture(std::weak_ptr<SDL2::Renderer>);

                virtual void load(const std::string &) override;

                virtual const std::set<std::string> &supportedFormats() const override;

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
