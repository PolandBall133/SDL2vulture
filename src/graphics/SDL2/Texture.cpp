#include "graphics/SDL2/Renderer.hpp"
#include "graphics/SDL2/Texture.hpp"
using namespace std;
namespace vulture{
    namespace graphics{
        namespace SDL2{
            void
            Texture::load(graphics::Renderer &renderer, const string &name){
            }

            void
            Texture::color(const Color &val){
                graphics::Texture::color(val);
                SDL_SetTextureColorMod(_handle.get(), val.r, val.g, val.b);
                SDL_SetTextureAlphaMod(_handle.get(), val.a);
            }
        }
    }
}
