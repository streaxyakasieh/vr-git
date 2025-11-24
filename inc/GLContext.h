#pragma once
#include <Window.h>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <X11/Xlib-xcb.h>




namespace Engine
{
    class Window;

    class GLContext
    {
        private: Window *      window;
        private: Display*      display;
        private: GLXContext    context;
        private: GLXFBConfig   fbConfig;
        private: GLXWindow     glxWindow;

        public:  GLContext           (Window* _window  );
        public: ~GLContext           (                 );
        public:  GLContext           (const GLContext& ) = delete;
        public:  GLContext           (      GLContext&&) = default;
        public:  GLContext& operator=(const GLContext& ) = delete;
        public:  GLContext& operator=(      GLContext&&) = default;

        public: void MakeCurrent();
        public: void SwapBuffers();
    };
}