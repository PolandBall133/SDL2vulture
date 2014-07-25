#include "graphics/SDL2/Renderer.hpp"
#include "graphics/SDL2/Texture.hpp"

using namespace std;
namespace vulture{
    namespace graphics{
        namespace SDL2{
            void
            Texture::load(SDL2::Renderer &renderer, const string &name){
            }

            void
            Texture::color(const Color &val){
                base::color(val);
                SDL_SetTextureColorMod(_handle.get(), val.r, val.g, val.b);
                SDL_SetTextureAlphaMod(_handle.get(), val.a);
            }
        }
    }
}
