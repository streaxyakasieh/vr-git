#pragma once
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <types/single.h>
#include <types/ivec2.h>
#include <types/uvec2.h>
#include <debug/Log.h>
#include <xcb/xcb_keysyms.h>
#include <xkbcommon/xkbcommon-x11.h>

namespace Engine
{
    class Window
    {
        friend class GLContext;

        private: static std::map<xcb_window_t, Window*> windows;
        private: static xcb_connection_t *              connection;
        private: static xcb_key_symbols_t*              keycodeSymbols;
        private: static xcb_screen_t     *              screen;
        private: static std::array<char, 64>            charBuffer;
        private: static xcb_atom_t                      deleteWindowAtom;
        private: static xcb_atom_t                      windowStateAtom;
        private: static xcb_atom_t                      maximizeXAtom;
        private: static xcb_atom_t                      maximizeYAtom;
        private: static xcb_atom_t                      minimizeAtom;

        public: static void PollEvents();

        private: str                       title;           public: inline const str  &             Title     (           ) const { return title;                             } public: void Title    (const str  & _value);
        private: ivec2                     position;        public: inline const ivec2&             Position  (           ) const { return position;                          } public: void Position (const ivec2& _value);
        private: uvec2                     size;            public: inline const uvec2&             Size      (           ) const { return size;                              } public: void Size     (const uvec2& _value);
        private: bool                      maximized;       public: inline       bool               Maximized (           ) const { return maximized;                         } public: void Maximized(const bool   _value);
        private: bool                      minimized;       public: inline       bool               Minimized (           ) const { return minimized;                         } public: void Minimized(const bool   _value);
        private: bool                      focused;         public: inline       bool               Focused   (           ) const { return focused;                           } public: void Focused  (const bool   _value);
        private: ivec2                     cursor;          public: inline const ivec2&             Cursor    (           ) const { return cursor;                            } public: void Cursor   (const ivec2& _value);
        private: bool                      open;            public: inline       bool               Open      (           ) const { return open;                              }
        private: std::set   <xcb_keysym_t> pressedKeys;     public: inline       bool               KeyDown   (u32 _key   ) const { return pressedKeys    .contains(_key   ); }
        private: std::set   <xcb_keysym_t> heldKeys;        public: inline       bool               KeyHeld   (u32 _key   ) const { return heldKeys       .contains(_key   ); }
        private: std::set   <xcb_keysym_t> releasedKeys;    public: inline       bool               KeyUp     (u32 _key   ) const { return releasedKeys   .contains(_key   ); }
        private: std::set   <xcb_button_t> pressedButtons;  public: inline       bool               ButtonDown(u08 _button) const { return pressedButtons .contains(_button); }
        private: std::set   <xcb_button_t> heldButtons;     public: inline       bool               ButtonHeld(u08 _button) const { return heldButtons    .contains(_button); }
        private: std::set   <xcb_button_t> releasedButtons; public: inline       bool               ButtonUp  (u08 _button) const { return releasedButtons.contains(_button); }
        private: std::vector<char        > pressedChars;    public: inline const std::vector<char>& Chars     (           ) const { return pressedChars;                      }
        private: xcb_window_t              handle;

        public:  Window(const str _title, const ivec2 _position, const uvec2 _size);
        public: ~Window();
        public:  Window           (const Window& ) = delete;
        public:  Window           (      Window&&) = default;
        public:  Window& operator=(const Window& ) = delete;
        public:  Window& operator=(      Window&&) = default;

        public: void Close();
    };
}