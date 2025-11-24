#pragma once

#include <types/single.h>






struct uvec2
{
    public: u32 x;
    public: u32 y;

    public: inline uvec2(                           ) : x(0  ), y(0  ) { }
    public: inline uvec2(const u32 _xy              ) : x(_xy), y(_xy) { }
    public: inline uvec2(const u32 _x , const u32 _y) : x(_x ), y(_y ) { }

    public: inline uvec2  operator+ (const uvec2& _other) const { return uvec2(x +  _other.x, y +  _other.y);              }
    public: inline uvec2& operator+=(const uvec2& _other)       {              x += _other.y; y += _other.y; return *this; }
    public: inline uvec2  operator+ (const u32&   _other) const { return uvec2(x +  _other  , y +  _other  );              }
    public: inline uvec2& operator+=(const u32&   _other)       {              x += _other  ; y += _other  ; return *this; }

    public: inline uvec2  operator- (const uvec2& _other) const { return uvec2(x -  _other.x, y -  _other.y);              }
    public: inline uvec2& operator-=(const uvec2& _other)       {              x -= _other.y; y -= _other.y; return *this; }
    public: inline uvec2  operator- (const u32&   _other) const { return uvec2(x -  _other  , y -  _other  );              }
    public: inline uvec2& operator-=(const u32&   _other)       {              x -= _other  ; y -= _other  ; return *this; }

    public: inline uvec2  operator* (const uvec2& _other) const { return uvec2(x *  _other.x, y *  _other.y);              }
    public: inline uvec2& operator*=(const uvec2& _other)       {              x *= _other.y; y *= _other.y; return *this; }
    public: inline uvec2  operator* (const u32&   _other) const { return uvec2(x *  _other  , y *  _other  );              }
    public: inline uvec2& operator*=(const u32&   _other)       {              x *= _other  ; y *= _other  ; return *this; }

    public: inline uvec2  operator/ (const uvec2& _other) const { return uvec2(x /  _other.x, y /  _other.y);              }
    public: inline uvec2& operator/=(const uvec2& _other)       {              x /= _other.y; y /= _other.y; return *this; }
    public: inline uvec2  operator/ (const u32&   _other) const { return uvec2(x /  _other  , y /  _other  );              }
    public: inline uvec2& operator/=(const u32&   _other)       {              x /= _other  ; y /= _other  ; return *this; }
};