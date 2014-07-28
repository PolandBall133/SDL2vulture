#include "graphics/SDL2/SpriteBatch.hpp"

using namespace std;
namespace vulture{
    namespace graphics{
        namespace SDL2{
            SpriteBatch::Drawer::Drawer(renderer_handle h):
                _renderer_handle(h){}

            void
            SpriteBatch::Drawer::texture(
                SDL2::Texture &texture,
                const Vector2 &position,
                const Rectangle &rect,
                double angle,
                const Point point
            ){
                bool pointProvided = point != -Point::one();
                SDL_RendererFlip rf;
                SDL_Rect clip = { rect.x, rect.y, rect.width, rect.height },
                         quad = { (int)position.x, (int)position.y, clip.w, clip.h };

                SDL_Point p;
                if(pointProvided) p = SDL_Point{ point.x, point.y };

                SDL2::Texture::HandleProvider hp;

                SDL_RenderCopyEx(
                    _renderer_handle.lock().get(),
                    hp.provide(texture).lock().get(),
                    &clip,
                    &quad,
                    angle,
                    pointProvided? &p : NULL,
                    rf
                );
            }

            void
            SpriteBatch::Drawer::texture(
                SDL2::Texture &texture,
                const Vector2 &position,
                double angle,
                const Point point
            ){
            }

            void
            SpriteBatch::Drawer::quad(
                const Rectangle &rect,
                const Color &color
            ){
                //renderer->drawingColor(backgroundColor());
                SDL_Rect r = { rect.x, rect. y, rect.width, rect.height };
            }

            void
            SpriteBatch::Drawer::line(
                const Point &p1,
                const Point &p2,
                const Color &color
            ){
            }

            SpriteBatch::SpriteBatch(renderer_handle renderer):
                _renderer_handle(renderer),
                _bgcolor(Color::White())
            {
                SDL2::Renderer::HandleProvider p;
                _drawerptr = make_shared<Drawer>(p.provide(*renderer.lock().get()));
            }

            void
            SpriteBatch::begin(){
                auto renderer = _renderer_handle.lock();
                renderer->drawingColor(backgroundColor());
                renderer->clear();
            }

            void
            SpriteBatch::end(){
                auto renderer = _renderer_handle.lock();
                renderer->present();
            }

            const Color
            SpriteBatch::backgroundColor() const{
                return _bgcolor;
            }

            void
            SpriteBatch::backgroundColor(const Color &color){
                _bgcolor = color;
            }

            SpriteBatch::base::Drawer &
            SpriteBatch::draw(){
                return *_drawerptr.get();
            }
        }
    }
}
