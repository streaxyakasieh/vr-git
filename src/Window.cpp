#include "debug/Log.h"
#include <Window.h>
#include <xcb/xcb.h>








namespace Engine
{
    std::map<xcb_window_t, Window*> Window::windows          = std::map<xcb_window_t, Window*>();
    xcb_connection_t *              Window::connection       = nullptr;
    xcb_key_symbols_t*              Window::keycodeSymbols   = nullptr;
    xcb_screen_t     *              Window::screen           = nullptr;
    std::array<char, 64>            Window::charBuffer       = std::array<char, 64>();
    xcb_atom_t                      Window::deleteWindowAtom = 0;
    xcb_atom_t                      Window::windowStateAtom  = 0;
    xcb_atom_t                      Window::maximizeXAtom    = 0;
    xcb_atom_t                      Window::maximizeYAtom    = 0;
    xcb_atom_t                      Window::minimizeAtom     = 0;

    void Window::PollEvents()
    {
        for (std::pair<const u32, Engine::Window *>& _pair : windows)
        {
            Window* _window = _pair.second;

            std::set<xcb_keysym_t>& _pressedKeys     = _window->pressedKeys;
            std::set<xcb_button_t>& _pressedButtons  = _window->pressedButtons;
            std::set<xcb_keysym_t>& _heldKeys        = _window->heldKeys;
            std::set<xcb_button_t>& _heldButtons     = _window->heldButtons;
            std::set<xcb_keysym_t>& _releasedKeys    = _window->releasedKeys;
            std::set<xcb_button_t>& _releasedButtons = _window->releasedButtons;

            _heldKeys       .insert(_pressedKeys   .begin(), _pressedKeys   .end());
            _heldButtons    .insert(_pressedButtons.begin(), _pressedButtons.end());

            _pressedKeys    .clear();
            _pressedButtons .clear();
            _releasedKeys   .clear();
            _releasedButtons.clear();

            _window->pressedChars.clear();
        }

        xcb_generic_event_t* _genericEvent;
        while((_genericEvent = xcb_poll_for_event(connection)))
        {
            i32 _responseType = _genericEvent->response_type & 0x7f;

            switch(_responseType)
            {
                case XCB_KEY_PRESS:
                {
                    xcb_key_press_event_t       * _event     = reinterpret_cast<xcb_key_press_event_t   *>(_genericEvent);
                    Window                      * _window    = windows[_event->event]; if (!_window) break;
                    xcb_keysym_t                  _key       = xcb_key_symbols_get_keysym(keycodeSymbols, _event->detail, 0);
                    xcb_keysym_t                  _keyChar   = xcb_key_symbols_get_keysym(keycodeSymbols, _event->detail, (_event->state & XCB_MOD_MASK_SHIFT) ^ ((_event->state & XCB_MOD_MASK_LOCK) >> 1));
                    u32                           _charCount = static_cast<u32>(xkb_keysym_to_utf8(_keyChar, charBuffer.data(), charBuffer.size()));

                    for (u32 _c = 0; _c < _charCount; _c++)
                    {
                        _window->pressedChars.push_back(charBuffer[_c]);
                    }

                    if (!_window->heldKeys.contains(_key))
                    {
                        _window->pressedKeys.insert(_key);
                    }
                    break;
                }
                case XCB_KEY_RELEASE:
                {
                    xcb_key_release_event_t     * _event  = reinterpret_cast<xcb_key_release_event_t    *>(_genericEvent);
                    Window                      * _window = windows[_event->event]; if (!_window) break;
                    xcb_keysym_t                  _key    = xcb_key_symbols_get_keysym(keycodeSymbols, _event->detail, 0);

                    _window->heldKeys    .erase (_key);
                    _window->releasedKeys.insert(_key);
                    break;
                }
                case XCB_BUTTON_PRESS:
                {
                    xcb_button_press_event_t    * _event  = reinterpret_cast<xcb_button_press_event_t   *>(_genericEvent);
                    Window                      * _window = windows[_event->event]; if (!_window) break;
                    xcb_button_t                  _button = _event->detail;

                    _window->pressedButtons.insert(_button);
                    break;
                }
                case XCB_BUTTON_RELEASE:
                {
                    xcb_button_release_event_t  * _event  = reinterpret_cast<xcb_button_release_event_t *>(_genericEvent);
                    Window                      * _window = windows[_event->event]; if (!_window) break;
                    xcb_button_t                  _button = _event->detail;

                    _window->heldButtons    .erase (_button);
                    _window->releasedButtons.insert(_button);
                    break;
                }
                case XCB_MOTION_NOTIFY:
                {
                    xcb_motion_notify_event_t   * _event = reinterpret_cast<xcb_motion_notify_event_t   *>(_genericEvent);
                    Window                      * _window = windows[_event->event]; if (!_window) break;

                    _window->cursor = ivec2(static_cast<i32>(_event->event_x), static_cast<i32>(_event->event_y));
                    break;
                }
                case XCB_CONFIGURE_NOTIFY:
                {
                    xcb_configure_notify_event_t* _event = reinterpret_cast<xcb_configure_notify_event_t*>(_genericEvent);
                    Window* _window = windows[_event->event]; if (!_window) break;

                    _window->position = ivec2(static_cast<i32>(_event->x    ), static_cast<i32>(_event->y     ));
                    _window->size     = uvec2(static_cast<u32>(_event->width), static_cast<u32>(_event->height));
                    break;
                }
                case XCB_FOCUS_IN:
                {
                    xcb_focus_in_event_t        * _event = reinterpret_cast<xcb_focus_in_event_t        *>(_genericEvent);
                    Window                      * _window = windows[_event->event]; if (!_window) break;

                    _window->focused = true;
                    break;
                }
                case XCB_FOCUS_OUT:
                {
                    xcb_focus_out_event_t       * _event = reinterpret_cast<xcb_focus_out_event_t       *>(_genericEvent);
                    Window                      * _window = windows[_event->event]; if (!_window) break;

                    _window->focused = false;
                    break;
                }
                case XCB_CLIENT_MESSAGE:
                {
                    xcb_client_message_event_t  * _event = reinterpret_cast<xcb_client_message_event_t  *>(_genericEvent);
                    Window* _window = windows[_event->window]; if (!_window) break;

                    if (_event->type == deleteWindowAtom)
                    {
                        _window->open = false;
                    }
                    else
                    {
                        xcb_get_atom_name_reply_t* _atomName = xcb_get_atom_name_reply(connection, xcb_get_atom_name(connection, _event->type), nullptr);

                        if (_atomName)
                        {
                            Log("Unused client atom: " + str(xcb_get_atom_name_name(_atomName), static_cast<size_t>(xcb_get_atom_name_name_length(_atomName))));
                            free(reinterpret_cast<void*>(_atomName));
                        }
                        else
                        {
                            Log("Unknown client atom: " + std::to_string(_event->type));
                        }
                    }
                    break;
                }
                case XCB_DESTROY_NOTIFY:
                {
                    // Unused event on any owned window destruction.
                    break;
                }
                case XCB_MAP_NOTIFY:
                {
                    // Unused event when a window is initially mapped to screen.
                    break;
                }
                case XCB_UNMAP_NOTIFY:
                {
                    // Unused event when a window is unmapped to screen, likely during destruction.
                    break;
                }
                case XCB_NONE:
                {
                    xcb_generic_error_t          * _error = reinterpret_cast<xcb_generic_error_t       *>(_genericEvent);

                    Error("XCB ERROR: " + std::to_string(_error->error_code ) + "." + std::to_string(_error->major_code) + "." + std::to_string(_error->minor_code));
                }
                default:
                {
                    Log("Unregistered event type: " + std::to_string(_responseType));
                    break;
                }
            }
            free(_genericEvent);
        }
    }

    void Window::Title    (const str  & _value)
    {
        title    = _value;

        xcb_change_property
        (
            connection,
            XCB_PROP_MODE_REPLACE,
            handle,
            XCB_ATOM_WM_NAME,
            XCB_ATOM_STRING,
            8,
            static_cast<u32>(title.length()),
            title.c_str()
        );
        xcb_flush(connection);
    }
    void Window::Position (const ivec2& _value)
    {
        position = _value;

        u16 _valueMask =
        (
            XCB_CONFIG_WINDOW_X |
            XCB_CONFIG_WINDOW_Y
        );
        i32 _valueList[] =
        {
            _value.x,
            _value.y,
        };

        xcb_configure_window
        (
            connection,
            handle,
            _valueMask,
            _valueList
        );
        xcb_flush(connection);
    }
    void Window::Size     (const uvec2& _value)
    {
        size = _value;

        u16 _valueMask =
        (
            XCB_CONFIG_WINDOW_WIDTH |
            XCB_CONFIG_WINDOW_HEIGHT
        );
        i32 _valueList[] =
        {
            i32(_value.x),
            i32(_value.y),
        };

        xcb_configure_window
        (
            connection,
            handle,
            _valueMask,
            _valueList
        );
        xcb_flush(connection);
    }
    void Window::Maximized(const bool   _value)
    {
        maximized = _value;

        xcb_client_message_event_t _maximizeEvent{};
        _maximizeEvent.response_type  = XCB_CLIENT_MESSAGE;
        _maximizeEvent.format         = 32;
        _maximizeEvent.window         = handle;
        _maximizeEvent.type           = windowStateAtom;
        _maximizeEvent.data.data32[0] = maximized ? 1 : 0;
        _maximizeEvent.data.data32[1] = maximizeXAtom;
        _maximizeEvent.data.data32[2] = maximizeYAtom;
        _maximizeEvent.data.data32[3] = 1;

        xcb_send_event
        (
            connection,
            false,
            screen->root,
            XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT |
            XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY,
            reinterpret_cast<char*>(&_maximizeEvent)
        );
        xcb_flush(connection);
    }
    void Window::Minimized(const bool   _value)
    {
        minimized = _value;

        xcb_client_message_event_t _minimizeEvent{};
        _minimizeEvent.response_type  = XCB_CLIENT_MESSAGE;
        _minimizeEvent.format         = 32;
        _minimizeEvent.window         = handle;
        _minimizeEvent.type           = windowStateAtom;
        _minimizeEvent.data.data32[0] = minimized ? 1 : 0;
        _minimizeEvent.data.data32[1] = minimizeAtom;
        _minimizeEvent.data.data32[2] = 0;
        _minimizeEvent.data.data32[3] = 1;

        xcb_send_event
        (
            connection,
            false,
            screen->root,
            XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT |
            XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY,
            reinterpret_cast<char*>(&_minimizeEvent)
        );
        xcb_flush(connection);
    }
    void Window::Focused  (const bool   _value)
    {
        focused = _value;

        if (focused)
        {
            xcb_set_input_focus
            (
                connection,
                XCB_INPUT_FOCUS_POINTER_ROOT,
                handle,
                XCB_CURRENT_TIME
            );
        }
        else
        {
            xcb_set_input_focus
            (
                connection,
                XCB_INPUT_FOCUS_POINTER_ROOT,
                screen->root,
                XCB_CURRENT_TIME
            );
        }
        xcb_flush(connection);
    }
    void Window::Cursor   (const ivec2& _value)
    {
        cursor = _value;

        // Note: Likely should change this function, or remove it for cross-compatibility sake due to Wayland not allowing
        //       cursor movement, but allowing cursor window-frame restriction, visibilty, and locking/centering.
        //       Plus, both cursor movement and restrictions are rather unecessary, especially for a VR engine or VR game.
        xcb_warp_pointer
        (
            connection,
            XCB_NONE,
            screen->root,
            0, 0, 0, 0,
            static_cast<i16>(_value.x), static_cast<i16>(_value.y)
        );
        xcb_flush(connection);
    }

    Window:: Window(const str _title, const ivec2 _position, const uvec2 _size)
    {
        // If this is the first window instance, connect to the X server and gather the screens.
        if (windows.size() == 0)
        {
            connection = xcb_connect(nullptr, nullptr);
            if (xcb_connection_has_error(connection) > 0) Error("Failed to connect with the X server.");

            const xcb_setup_t          * _setup          = xcb_get_setup           ( connection);
            const xcb_screen_iterator_t  _screenIterator = xcb_setup_roots_iterator( _setup    );

            keycodeSymbols  = xcb_key_symbols_alloc(connection );
            screen          = _screenIterator.data;

            xcb_intern_atom_reply_t* _deleteWindow = xcb_intern_atom_reply(connection, xcb_intern_atom(connection, 0, strlen("WM_PROTOCOLS"                ), "WM_PROTOCOLS"                ), nullptr);
            xcb_intern_atom_reply_t* _windowState  = xcb_intern_atom_reply(connection, xcb_intern_atom(connection, 0, strlen("_NET_WM_STATE"               ), "_NET_WM_STATE"               ), nullptr);
            xcb_intern_atom_reply_t* _maximizeX    = xcb_intern_atom_reply(connection, xcb_intern_atom(connection, 0, strlen("_NET_WM_STATE_MAXIMIZED_HORZ"), "_NET_WM_STATE_MAXIMIZED_HORZ"), nullptr);
            xcb_intern_atom_reply_t* _maximizeY    = xcb_intern_atom_reply(connection, xcb_intern_atom(connection, 0, strlen("_NET_WM_STATE_MAXIMIZED_VERT"), "_NET_WM_STATE_MAXIMIZED_VERT"), nullptr);
            xcb_intern_atom_reply_t* _minimize     = xcb_intern_atom_reply(connection, xcb_intern_atom(connection, 0, strlen("_NET_WM_STATE_HIDDEN"        ), "_NET_WM_STATE_HIDDEN"        ), nullptr);
            deleteWindowAtom = _deleteWindow->atom;
            windowStateAtom  = _windowState ->atom;
            maximizeXAtom    = _maximizeX   ->atom;
            maximizeYAtom    = _maximizeY   ->atom;
            minimizeAtom     = _minimize    ->atom;
            free(_deleteWindow);
            free(_windowState );
            free(_maximizeX   );
            free(_maximizeY   );
            free(_minimize    );
        }

        // Construct the window handle.
        u16 _valueMask =
        (
            XCB_CW_EVENT_MASK
        );
        i32 _valueList[] =
        {
            XCB_EVENT_MASK_KEY_PRESS             |
            XCB_EVENT_MASK_KEY_RELEASE           |
            XCB_EVENT_MASK_BUTTON_PRESS          |
            XCB_EVENT_MASK_BUTTON_RELEASE        |
            XCB_EVENT_MASK_POINTER_MOTION        |
            XCB_EVENT_MASK_STRUCTURE_NOTIFY      |
            XCB_EVENT_MASK_FOCUS_CHANGE          ,
        };

        handle = xcb_generate_id(connection);
        xcb_create_window
        (
            connection,
            XCB_COPY_FROM_PARENT,
            handle,
            screen->root,
            static_cast<i16>(_position.x), static_cast<i16>(_position.y),
            static_cast<u16>(_size    .x), static_cast<u16>(_size    .y),
            10,
            XCB_WINDOW_CLASS_INPUT_OUTPUT,
            screen->root_visual,
            _valueMask,
           &_valueList
        );

        position = _position;
        size     = _size;
        open     = true;

        Title(_title);

        windows[handle] = this;

        xcb_map_window(connection, handle);

        if (xcb_flush(connection) <= 0) Error("Failed to flush changes to the X server.");
    }
    Window::~Window()
    {
        windows.erase(handle);

        xcb_destroy_window(connection, handle);
        xcb_flush         (connection        );

        // If this is the last window instance, disconnect from the X server.
        if (windows.size() == 0)
        {
            xcb_key_symbols_free(keycodeSymbols);
            xcb_disconnect(connection);
        }
    }
}