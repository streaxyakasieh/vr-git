#include <GLContext.h>








namespace Engine
{
    GLContext::GLContext(Window* _window)
    {
        window  = _window;
        display = XOpenDisplay(nullptr);
        if (!display) Error("Failed to open X server rendering context display.");

        XSetEventQueueOwner(display, XCBOwnsEventQueue);

        xcb_connection_t* _connection = XGetXCBConnection(display);
        if (!_connection) Error("Failed to get X server rendering connection.");

        static int fbAttribs[] =
        {
            GLX_X_RENDERABLE   , True,
            GLX_DRAWABLE_TYPE  , GLX_WINDOW_BIT,
            GLX_RENDER_TYPE    , GLX_RGBA_BIT,
            GLX_X_VISUAL_TYPE  , GLX_TRUE_COLOR,
            GLX_RED_SIZE       , 8,
            GLX_GREEN_SIZE     , 8,
            GLX_BLUE_SIZE      , 8,
            GLX_ALPHA_SIZE     , 8,
            GLX_DEPTH_SIZE     , 24,
            GLX_DOUBLEBUFFER   , True,
            None
        };

        int fbCount = 0;
        GLXFBConfig* configs = glXChooseFBConfig(display,
                                                 DefaultScreen(display),
                                                 fbAttribs,
                                                 &fbCount);
        if (!configs || fbCount == 0) Error("GLContext: glXChooseFBConfig failed");

        fbConfig = configs[0];
        XFree(configs);

        context = glXCreateNewContext(display, fbConfig, GLX_RGBA_TYPE, nullptr, True);
        if (!context) Error("GLContext: glXCreateNewContext failed");

        glxWindow = glXCreateWindow(display, fbConfig, window->handle, nullptr);
        if (!glxWindow) Error("GLContext: glXCreateWindow failed");

        if (!glXMakeCurrent(display, glxWindow, context))
            Error("GLContext: glXMakeCurrent failed");
    }
    GLContext::~GLContext()
    {
        if (display)
        {
            glXMakeCurrent(display, None, nullptr);

            if (glxWindow)
                glXDestroyWindow(display, glxWindow);

            if (context)
                glXDestroyContext(display, context);

            XCloseDisplay(display);
        }
    }

    void GLContext::MakeCurrent()
    {
        glXMakeCurrent(display, glxWindow, context);
    }
    void GLContext::SwapBuffers()
    {
        glXSwapBuffers(display, glxWindow);
    }
}