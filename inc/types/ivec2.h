#pragma once

#include <types/single.h>






struct ivec2
{
    public: i32 x;
    public: i32 y;

    public: inline ivec2(                           ) : x(0  ), y(0  ) { }
    public: inline ivec2(const i32 _xy              ) : x(_xy), y(_xy) { }
    public: inline ivec2(const i32 _x , const i32 _y) : x(_x ), y(_y ) { }

    public: inline ivec2  operator+ (const ivec2& _other) const { return ivec2(x +  _other.x, y +  _other.y);              }
    public: inline ivec2& operator+=(const ivec2& _other)       {              x += _other.y; y += _other.y; return *this; }
    public: inline ivec2  operator+ (const i32&   _other) const { return ivec2(x +  _other  , y +  _other  );              }
    public: inline ivec2& operator+=(const i32&   _other)       {              x += _other  ; y += _other  ; return *this; }

    public: inline ivec2  operator- (const ivec2& _other) const { return ivec2(x -  _other.x, y -  _other.y);              }
    public: inline ivec2& operator-=(const ivec2& _other)       {              x -= _other.y; y -= _other.y; return *this; }
    public: inline ivec2  operator- (const i32&   _other) const { return ivec2(x -  _other  , y -  _other  );              }
    public: inline ivec2& operator-=(const i32&   _other)       {              x -= _other  ; y -= _other  ; return *this; }

    public: inline ivec2  operator* (const ivec2& _other) const { return ivec2(x *  _other.x, y *  _other.y);              }
    public: inline ivec2& operator*=(const ivec2& _other)       {              x *= _other.y; y *= _other.y; return *this; }
    public: inline ivec2  operator* (const i32&   _other) const { return ivec2(x *  _other  , y *  _other  );              }
    public: inline ivec2& operator*=(const i32&   _other)       {              x *= _other  ; y *= _other  ; return *this; }

    public: inline ivec2  operator/ (const ivec2& _other) const { return ivec2(x /  _other.x, y /  _other.y);              }
    public: inline ivec2& operator/=(const ivec2& _other)       {              x /= _other.y; y /= _other.y; return *this; }
    public: inline ivec2  operator/ (const i32&   _other) const { return ivec2(x /  _other  , y /  _other  );              }
    public: inline ivec2& operator/=(const i32&   _other)       {              x /= _other  ; y /= _other  ; return *this; }
};