#include "windows/SDL2/Window.hpp"

namespace vulture{
    namespace windows{
        namespace SDL2{
            Window::Window(const std::string &title, const Rectangle &info, Window::Flags flags):
                windows::Window(title, info, flags)
            {
                _handle = window_handle(
                    SDL_CreateWindow(title.c_str(), info.x, info.y, info.width, info.height, flags),
                    SDL_DestroyWindow
                );
            }

            const std::string
            Window::title() const{
                return std::string(SDL_GetWindowTitle(_handle.get()));
            }

            void
            Window::title(const std::string &value){
                SDL_SetWindowTitle(_handle.get(), value.c_str());
            }

            const Size
            Window::size() const{
                int w, h;
                SDL_GetWindowSize(_handle.get(), &w, &h);
                return Size(w, h);
            };

            void
            Window::size(const Size &val){
                SDL_SetWindowSize(_handle.get(), (int)val.width, (int)val.height);
            }

            const Point
            Window::position() const{
                int x, y;
                SDL_GetWindowPosition(_handle.get(), &x, &y);
                return Point(x, y);
            }

            void
            Window::position(const Point &val){
                SDL_SetWindowPosition(_handle.get(), (int)val.x, (int)val.y);
            }

            uint32_t
            Window::ID() const{
                return SDL_GetWindowID(_handle.get());
            }

            void
            Window::onClosed(const windows::Event::Closed &closed){
                Window::onClosed(closed);
                SDL_DestroyWindow(_handle.get());
                _handle = nullptr;
            }

            Window *
            Window::Factory::create(const std::string &title, const Rectangle &rect, const Flags flags){
                return new Window(title, rect, flags);
            }

            Window::HandleProvider::handle
            Window::HandleProvider::provide(Window &window){
                return handle(window._handle);
            }
        }
    }
}
