#include "core/SDL2/TicksProvider.hpp"

namespace vulture{
    namespace core{
        namespace SDL2{
            time_t
            TicksProvider::ticks(){
                return SDL_GetTicks();
            }
        }
    }
}
