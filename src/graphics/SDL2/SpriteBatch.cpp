#include "graphics/SDL2/SpriteBatch.hpp"

using namespace std;
namespace vulture{
    namespace graphics{
        namespace SDL2{
            SpriteBatch::Drawer::Drawer(renderer_handle h):
                _renderer_handle(h)
            {
                SDL2::Renderer::HandleProvider hp;
                _sdlrenderer_handle = hp.provide(*h.lock().get());
            }

            void
            SpriteBatch::Drawer::texture(
                SDL2::Texture &texture,
                const Rectangle &src,
                const Rectangle &dst,
                double angle,
                const Point point
            ){
                bool pointProvided = point != -Point::one();
                SDL_RendererFlip rf;
                SDL_Rect clip = { (int)src.x, (int)src.y, (int)src.width, (int)src.height },
                         quad = { (int)dst.x, (int)dst.y, (int)dst.width, (int)dst.height };

                SDL_Point p;
                if(pointProvided) p = SDL_Point{ point.x, point.y };

                SDL2::Texture::HandleProvider hp;

                SDL_RenderCopyEx(
                    _sdlrenderer_handle.lock().get(),
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
                const Point &pos,
                double angle,
                const Point point
            ){
                this->texture(
                    texture,
                    Rectangle(
                        Point::zero(),
                        texture.size()
                    ),
                    Rectangle(
                        Point(pos.x, pos.y),
                        texture.size()
                    ),
                    angle,
                    point
                );
            }

            void
            SpriteBatch::Drawer::quad(
                const Rectangle &rect,
                const Color &color
            ){
                _renderer_handle.lock()->drawingColor(color);
                SDL_Rect r = { (int)rect.x, (int)rect.y, (int)rect.width, (int)rect.height };
                SDL_RenderDrawRect(_sdlrenderer_handle.lock().get(), &r);
            }

            void
            SpriteBatch::Drawer::line(
                const Point &p1,
                const Point &p2,
                const Color &color
            ){
                _renderer_handle.lock()->drawingColor(color);
                SDL_RenderDrawLine(_sdlrenderer_handle.lock().get(), p1.x, p1.y, p2.x, p2.y);
            }

            SpriteBatch::SpriteBatch(renderer_handle renderer):
                _renderer_handle(renderer),
                _bgcolor(Color::White())
            {
                _drawerptr = make_shared<Drawer>(renderer);
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
