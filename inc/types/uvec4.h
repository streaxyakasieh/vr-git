#pragma once

#include <types/uvec3.h>
#include <types/uvec2.h>
#include <types/single.h>




struct uvec4
{
    public: u32 x;
    public: u32 y;
    public: u32 z;
    public: u32 w;

    public: inline uvec4(                                                                  ) : x(0     ), y(0     ), z(0     ), w(0     ) { }
    public: inline uvec4(const u32   _xyzw                                                 ) : x(_xyzw ), y(_xyzw ), z(_xyzw ), w(_xyzw ) { }
    public: inline uvec4(const uvec3 _xyz , const u32   _w                                 ) : x(_xyz.x), y(_xyz.y), z(_xyz.z), w(_w    ) { }
    public: inline uvec4(const u32   _x   , const uvec3 _yzw                               ) : x(_x    ), y(_yzw.x), z(_yzw.y), w(_yzw.z) { }
    public: inline uvec4(const uvec2 _xy  , const uvec2 _zw                                ) : x(_xy.x ), y(_xy.y ), z(_zw.x ), w(_zw.y ) { }
    public: inline uvec4(const uvec2 _xy  , const u32   _z  , const u32   _w               ) : x(_xy.x ), y(_xy.y ), z(_z    ), w(_w    ) { }
    public: inline uvec4(const u32   _x   , const uvec2 _yz , const u32   _w               ) : x(_x    ), y(_yz.x ), z(_yz.y ), w(_w    ) { }
    public: inline uvec4(const u32   _x   , const u32   _y  , const uvec2 _zw              ) : x(_x    ), y(_y    ), z(_zw.x ), w(_zw.y ) { }
    public: inline uvec4(const u32   _x   , const u32   _y  , const u32   _z , const u32 _w) : x(_x    ), y(_y    ), z(_z    ), w(_w    ) { }

    public: inline uvec4  operator+ (const uvec4& _other) const { return uvec4(x +  _other.x, y +  _other.y, z +  _other.z, w +  _other.w);               }
    public: inline uvec4& operator+=(const uvec4& _other)       {              x += _other.y; y += _other.y; z += _other.z; w += _other.w ; return *this; }
    public: inline uvec4  operator+ (const u32&   _other) const { return uvec4(x +  _other  , y +  _other  , z +  _other  , w +  _other  );               }
    public: inline uvec4& operator+=(const u32&   _other)       {              x += _other  ; y += _other  ; z += _other  ; w += _other   ; return *this; }

    public: inline uvec4  operator- (const uvec4& _other) const { return uvec4(x -  _other.x, y -  _other.y, z -  _other.z, w -  _other.w);               }
    public: inline uvec4& operator-=(const uvec4& _other)       {              x -= _other.y; y -= _other.y; z -= _other.z; w -= _other.w ; return *this; }
    public: inline uvec4  operator- (const u32&   _other) const { return uvec4(x -  _other  , y -  _other  , z -  _other  , w -  _other  );               }
    public: inline uvec4& operator-=(const u32&   _other)       {              x -= _other  ; y -= _other  ; z -= _other  ; w -= _other   ; return *this; }

    public: inline uvec4  operator* (const uvec4& _other) const { return uvec4(x *  _other.x, y *  _other.y, z *  _other.z, w *  _other.w);               }
    public: inline uvec4& operator*=(const uvec4& _other)       {              x *= _other.y; y *= _other.y; z *= _other.z; w *= _other.w ; return *this; }
    public: inline uvec4  operator* (const u32&   _other) const { return uvec4(x *  _other  , y *  _other  , z *  _other  , w *  _other  );               }
    public: inline uvec4& operator*=(const u32&   _other)       {              x *= _other  ; y *= _other  ; z *= _other  ; w *= _other   ; return *this; }

    public: inline uvec4  operator/ (const uvec4& _other) const { return uvec4(x /  _other.x, y /  _other.y, z /  _other.z, w /  _other.w);               }
    public: inline uvec4& operator/=(const uvec4& _other)       {              x /= _other.y; y /= _other.y; z /= _other.z; w /= _other.w ; return *this; }
    public: inline uvec4  operator/ (const u32&   _other) const { return uvec4(x /  _other  , y /  _other  , z /  _other  , w /  _other  );               }
    public: inline uvec4& operator/=(const u32&   _other)       {              x /= _other  ; y /= _other  ; z /= _other  ; w /= _other   ; return *this; }
};