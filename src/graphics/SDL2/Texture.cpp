#include "graphics/SDL2/Renderer.hpp"
#include "graphics/SDL2/Texture.hpp"

using namespace std;

namespace vulture{
    namespace graphics{
        namespace SDL2{
            Texture::Texture(weak_ptr<SDL2::Renderer> renderer, const Color c):
                base(c)
            {
                SDL2::Renderer::HandleProvider provider;
                _renderer_handle = provider.provide(*renderer.lock().get());
            }

            void
            Texture::load(const string &name){
                SDL_Surface *surface = SDL_LoadBMP(name.c_str());
                _handle = texture_handle{
                    SDL_CreateTextureFromSurface(
                        _renderer_handle.lock().get(),
                        surface
                    ),
                    SDL_DestroyTexture
                };
                SDL_FreeSurface(surface);
            }

            const set<string> &
            Texture::supportedFormats() const{
                static set<string> supported_formats = {
                    "bmp"
                };
                return supported_formats;
            }

            void
            Texture::color(const Color &val){
                base::color(val);
                SDL_SetTextureColorMod(_handle.get(), val.r, val.g, val.b);
                SDL_SetTextureAlphaMod(_handle.get(), val.a);
            }

            Texture::HandleProvider::handle
            Texture::HandleProvider::provide(SDL2::Texture &texture){
                return handle(texture._handle);
            }
        }
    }
}
