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
            class Texture : public graphics::Texture{
                friend class HandleProvider;
            public:
                Texture(std::weak_ptr<SDL2::Renderer>, const Color = Color::Transparent());

                virtual void load(const std::string &) override;

                virtual const std::set<std::string> &supportedFormats() const override;

                virtual void color(const Color &) override;

                struct HandleProvider;
            protected:
                typedef std::weak_ptr<SDL_Renderer> renderer_handle;
                renderer_handle _renderer_handle;
                typedef std::shared_ptr<SDL_Texture> texture_handle;
                texture_handle _handle;
            private:
                void sdlQuery();
                typedef graphics::Texture base;
            };

            struct Texture::HandleProvider{
                typedef std::weak_ptr<SDL_Texture> handle;
                handle provide(SDL2::Texture &);
            };
        }
    }
}
