#include "graphics/SDL2/Renderer.hpp"

namespace vulture{
    namespace graphics{
        namespace SDL2{
            Renderer::Renderer(std::weak_ptr<windows::SDL2::Window> window)
            {
                windows::SDL2::Window::HandleProvider provider;
                auto hwindow = provider.provide(*window.lock().get());
                _handle = renderer_handle(
                    SDL_CreateRenderer(hwindow.lock().get(), -1, SDL_RENDERER_ACCELERATED),
                    SDL_DestroyRenderer
                );
            }

            void
            Renderer::clear(){
                SDL_RenderClear(_handle.get());
            }

            void
            Renderer::present(){
                SDL_RenderPresent(_handle.get());
            }

            void
            Renderer::drawingColor(const Color &color){
                SDL_SetRenderDrawColor(
                    _handle.get(),
                    color.r, color.g, color.b, color.a
                );
            }

            const Rectangle
            Renderer::viewPort() const{
                SDL_Rect r;
                SDL_RenderGetViewport(_handle.get(), &r);
                return Rectangle(r.x, r.y, r.w, r.h);
            }

            void
            Renderer::viewPort(const Rectangle &val){
                SDL_Rect r = { val.x, val.y, val.width, val.height };
                SDL_RenderSetViewport(_handle.get(), &r);
            }

            const Vector2
            Renderer::scale() const{
                float sx, sy;
                SDL_RenderGetScale(_handle.get(), &sx, &sy);
                return Vector2((double)sx, (double)sy);
            }

            void
            Renderer::scale(const Vector2 &val){
                float sx = (float)val.x, sy = (float)val.y;
                SDL_RenderSetScale(_handle.get(), sx, sy);
            }

            const Size
            Renderer::logicalSize() const{
                int w, h;
                SDL_RenderGetLogicalSize(_handle.get(), &w, &h);
                return Size((uint32_t)w, (uint32_t) h);
            }

            void
            Renderer::logicalSize(const Size &val){
                int w = (int)val.width, h = (int)val.height;
                SDL_RenderSetLogicalSize(_handle.get(), w, h);
            };

            Renderer::HandleProvider::handle
            Renderer::HandleProvider::provide(Renderer &renderer){
                return handle(renderer._handle);
            }
        }
    }
}
