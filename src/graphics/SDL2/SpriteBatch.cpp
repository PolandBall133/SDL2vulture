#include "graphics/SDL2/SpriteBatch.hpp"

using namespace std;
namespace vulture{
    namespace graphics{
        namespace SDL2{
            SpriteBatch::SpriteBatch(renreder_handle hrenderer):
                _renderer_handle(hrenderer){}

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
        }
    }
}
