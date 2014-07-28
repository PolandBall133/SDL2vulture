#include "graphics/SDL2/SpriteBatch.hpp"

using namespace std;
namespace vulture{
    namespace graphics{
        namespace SDL2{
            void
            SpriteBatch::Drawer::texture(
                SDL2::Texture &texture,
                const Vector2 &position,
                const Rectangle &rect,
                double angle,
                const Point
            ){
            }

            void
            SpriteBatch::Drawer::texture(
                SDL2::Texture &texture,
                const Vector2 &position,
                double angle,
                const Point
            ){
            }

            void
            SpriteBatch::Drawer::quad(
                const Rectangle &rect,
                const Color &color
            ){
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
                _bgcolor(Color::White()){}

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
        }
    }
}
