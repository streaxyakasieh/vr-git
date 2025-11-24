#include "GLContext.h"
#include <GL/gl.h>
#include <Window.h>








int main()
{
    Engine::Window _window("timmy-engine", ivec2(0, 0), uvec2(960, 540));
    Engine::GLContext _context(&_window);

    i32 _color = 0;
    while(_window.Open())
    {
        Engine::Window::PollEvents();

        _context.MakeCurrent();

        _color += 244 + 249 * 255 + 254 * 255 * 255;
        glClearColor((_color % 255) * (1.0f / 255.0f), ((_color / 255) % 255) * (1.0f / 255.0f), ((_color / 255 / 255) % 255) * (1.0f / 255.0f), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        _context.SwapBuffers();
    }
}