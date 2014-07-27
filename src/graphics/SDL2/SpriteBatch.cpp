#include "graphics/SDL2/SpriteBatch.hpp"

using namespace std;
namespace vulture{
    namespace graphics{
        namespace SDL2{
            SpriteBatch::SpriteBatch(renreder_handle hrenderer):
                _renderer_handle(hrenderer){}
        }
    }
}
