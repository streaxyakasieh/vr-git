#pragma once

#include <types/fvec3.h>
#include <types/fvec2.h>
#include <types/single.h>




struct fvec4
{
    public: f32 x;
    public: f32 y;
    public: f32 z;
    public: f32 w;

    public: inline fvec4(                                                                  ) : x(0     ), y(0     ), z(0     ), w(0     ) { }
    public: inline fvec4(const f32   _xyzw                                                 ) : x(_xyzw ), y(_xyzw ), z(_xyzw ), w(_xyzw ) { }
    public: inline fvec4(const fvec3 _xyz , const f32   _w                                 ) : x(_xyz.x), y(_xyz.y), z(_xyz.z), w(_w    ) { }
    public: inline fvec4(const f32   _x   , const fvec3 _yzw                               ) : x(_x    ), y(_yzw.x), z(_yzw.y), w(_yzw.z) { }
    public: inline fvec4(const fvec2 _xy  , const fvec2 _zw                                ) : x(_xy.x ), y(_xy.y ), z(_zw.x ), w(_zw.y ) { }
    public: inline fvec4(const fvec2 _xy  , const f32   _z  , const f32   _w               ) : x(_xy.x ), y(_xy.y ), z(_z    ), w(_w    ) { }
    public: inline fvec4(const f32   _x   , const fvec2 _yz , const f32   _w               ) : x(_x    ), y(_yz.x ), z(_yz.y ), w(_w    ) { }
    public: inline fvec4(const f32   _x   , const f32   _y  , const fvec2 _zw              ) : x(_x    ), y(_y    ), z(_zw.x ), w(_zw.y ) { }
    public: inline fvec4(const f32   _x   , const f32   _y  , const f32   _z , const f32 _w) : x(_x    ), y(_y    ), z(_z    ), w(_w    ) { }

    public: inline fvec4  operator+ (const fvec4& _other) const { return fvec4(x +  _other.x, y +  _other.y, z +  _other.z, w +  _other.w);               }
    public: inline fvec4& operator+=(const fvec4& _other)       {              x += _other.y; y += _other.y; z += _other.z; w += _other.w ; return *this; }
    public: inline fvec4  operator+ (const f32&   _other) const { return fvec4(x +  _other  , y +  _other  , z +  _other  , w +  _other  );               }
    public: inline fvec4& operator+=(const f32&   _other)       {              x += _other  ; y += _other  ; z += _other  ; w += _other   ; return *this; }

    public: inline fvec4  operator- (const fvec4& _other) const { return fvec4(x -  _other.x, y -  _other.y, z -  _other.z, w -  _other.w);               }
    public: inline fvec4& operator-=(const fvec4& _other)       {              x -= _other.y; y -= _other.y; z -= _other.z; w -= _other.w ; return *this; }
    public: inline fvec4  operator- (const f32&   _other) const { return fvec4(x -  _other  , y -  _other  , z -  _other  , w -  _other  );               }
    public: inline fvec4& operator-=(const f32&   _other)       {              x -= _other  ; y -= _other  ; z -= _other  ; w -= _other   ; return *this; }

    public: inline fvec4  operator* (const fvec4& _other) const { return fvec4(x *  _other.x, y *  _other.y, z *  _other.z, w *  _other.w);               }
    public: inline fvec4& operator*=(const fvec4& _other)       {              x *= _other.y; y *= _other.y; z *= _other.z; w *= _other.w ; return *this; }
    public: inline fvec4  operator* (const f32&   _other) const { return fvec4(x *  _other  , y *  _other  , z *  _other  , w *  _other  );               }
    public: inline fvec4& operator*=(const f32&   _other)       {              x *= _other  ; y *= _other  ; z *= _other  ; w *= _other   ; return *this; }

    public: inline fvec4  operator/ (const fvec4& _other) const { return fvec4(x /  _other.x, y /  _other.y, z /  _other.z, w /  _other.w);               }
    public: inline fvec4& operator/=(const fvec4& _other)       {              x /= _other.y; y /= _other.y; z /= _other.z; w /= _other.w ; return *this; }
    public: inline fvec4  operator/ (const f32&   _other) const { return fvec4(x /  _other  , y /  _other  , z /  _other  , w /  _other  );               }
    public: inline fvec4& operator/=(const f32&   _other)       {              x /= _other  ; y /= _other  ; z /= _other  ; w /= _other   ; return *this; }
};