#pragma once

#include <types/single.h>






struct fvec2
{
    public: f32 x;
    public: f32 y;

    public: inline fvec2(                           ) : x(0  ), y(0  ) { }
    public: inline fvec2(const f32 _xy              ) : x(_xy), y(_xy) { }
    public: inline fvec2(const f32 _x , const f32 _y) : x(_x ), y(_y ) { }

    public: inline fvec2  operator+ (const fvec2& _other) const { return fvec2(x +  _other.x, y +  _other.y);              }
    public: inline fvec2& operator+=(const fvec2& _other)       {              x += _other.y; y += _other.y; return *this; }
    public: inline fvec2  operator+ (const f32&   _other) const { return fvec2(x +  _other  , y +  _other  );              }
    public: inline fvec2& operator+=(const f32&   _other)       {              x += _other  ; y += _other  ; return *this; }

    public: inline fvec2  operator- (const fvec2& _other) const { return fvec2(x -  _other.x, y -  _other.y);              }
    public: inline fvec2& operator-=(const fvec2& _other)       {              x -= _other.y; y -= _other.y; return *this; }
    public: inline fvec2  operator- (const f32&   _other) const { return fvec2(x -  _other  , y -  _other  );              }
    public: inline fvec2& operator-=(const f32&   _other)       {              x -= _other  ; y -= _other  ; return *this; }

    public: inline fvec2  operator* (const fvec2& _other) const { return fvec2(x *  _other.x, y *  _other.y);              }
    public: inline fvec2& operator*=(const fvec2& _other)       {              x *= _other.y; y *= _other.y; return *this; }
    public: inline fvec2  operator* (const f32&   _other) const { return fvec2(x *  _other  , y *  _other  );              }
    public: inline fvec2& operator*=(const f32&   _other)       {              x *= _other  ; y *= _other  ; return *this; }

    public: inline fvec2  operator/ (const fvec2& _other) const { return fvec2(x /  _other.x, y /  _other.y);              }
    public: inline fvec2& operator/=(const fvec2& _other)       {              x /= _other.y; y /= _other.y; return *this; }
    public: inline fvec2  operator/ (const f32&   _other) const { return fvec2(x /  _other  , y /  _other  );              }
    public: inline fvec2& operator/=(const f32&   _other)       {              x /= _other  ; y /= _other  ; return *this; }
};