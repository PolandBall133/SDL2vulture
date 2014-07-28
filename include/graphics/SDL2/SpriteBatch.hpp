#pragma once

#include "graphics/SpriteBatch.hpp"
#include "graphics/SDL2/Renderer.hpp"
#include "graphics/SDL2/Texture.hpp"

#include "SDL2/SDL.h"

#include <memory>

namespace vulture{
    namespace graphics{
        namespace SDL2{
            class SpriteBatch : public graphics::SpriteBatch<SDL2::Texture>{
                typedef graphics::SpriteBatch<SDL2::Texture> base;
            protected:
                typedef std::weak_ptr<SDL2::Renderer> renderer_handle;
                renderer_handle _renderer_handle;

                Color _bgcolor;

                struct Drawer : public base::Drawer{
                    virtual void texture(
                        SDL2::Texture &,
                        const Vector2 &,
                        const Rectangle &,
                        double = 0.0,
                        const Point = Point::zero()
                    ) override;

                    virtual void texture(
                        SDL2::Texture &,
                        const Vector2 &,
                        double = 0.0,
                        const Point = Point::zero()
                    ) override;

                    virtual void quad(
                        const Rectangle &,
                        const Color &
                    ) override;

                    virtual void line(
                        const Point &,
                        const Point &,
                        const Color &
                    ) override;
                };
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
