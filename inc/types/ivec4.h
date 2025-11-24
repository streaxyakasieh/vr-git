#pragma once

#include <types/ivec3.h>
#include <types/ivec2.h>
#include <types/single.h>




struct ivec4
{
    public: i32 x;
    public: i32 y;
    public: i32 z;
    public: i32 w;

    public: inline ivec4(                                                                  ) : x(0     ), y(0     ), z(0     ), w(0     ) { }
    public: inline ivec4(const i32   _xyzw                                                 ) : x(_xyzw ), y(_xyzw ), z(_xyzw ), w(_xyzw ) { }
    public: inline ivec4(const ivec3 _xyz , const i32   _w                                 ) : x(_xyz.x), y(_xyz.y), z(_xyz.z), w(_w    ) { }
    public: inline ivec4(const i32   _x   , const ivec3 _yzw                               ) : x(_x    ), y(_yzw.x), z(_yzw.y), w(_yzw.z) { }
    public: inline ivec4(const ivec2 _xy  , const ivec2 _zw                                ) : x(_xy.x ), y(_xy.y ), z(_zw.x ), w(_zw.y ) { }
    public: inline ivec4(const ivec2 _xy  , const i32   _z  , const i32   _w               ) : x(_xy.x ), y(_xy.y ), z(_z    ), w(_w    ) { }
    public: inline ivec4(const i32   _x   , const ivec2 _yz , const i32   _w               ) : x(_x    ), y(_yz.x ), z(_yz.y ), w(_w    ) { }
    public: inline ivec4(const i32   _x   , const i32   _y  , const ivec2 _zw              ) : x(_x    ), y(_y    ), z(_zw.x ), w(_zw.y ) { }
    public: inline ivec4(const i32   _x   , const i32   _y  , const i32   _z , const i32 _w) : x(_x    ), y(_y    ), z(_z    ), w(_w    ) { }

    public: inline ivec4  operator+ (const ivec4& _other) const { return ivec4(x +  _other.x, y +  _other.y, z +  _other.z, w +  _other.w);               }
    public: inline ivec4& operator+=(const ivec4& _other)       {              x += _other.y; y += _other.y; z += _other.z; w += _other.w ; return *this; }
    public: inline ivec4  operator+ (const i32&   _other) const { return ivec4(x +  _other  , y +  _other  , z +  _other  , w +  _other  );               }
    public: inline ivec4& operator+=(const i32&   _other)       {              x += _other  ; y += _other  ; z += _other  ; w += _other   ; return *this; }

    public: inline ivec4  operator- (const ivec4& _other) const { return ivec4(x -  _other.x, y -  _other.y, z -  _other.z, w -  _other.w);               }
    public: inline ivec4& operator-=(const ivec4& _other)       {              x -= _other.y; y -= _other.y; z -= _other.z; w -= _other.w ; return *this; }
    public: inline ivec4  operator- (const i32&   _other) const { return ivec4(x -  _other  , y -  _other  , z -  _other  , w -  _other  );               }
    public: inline ivec4& operator-=(const i32&   _other)       {              x -= _other  ; y -= _other  ; z -= _other  ; w -= _other   ; return *this; }

    public: inline ivec4  operator* (const ivec4& _other) const { return ivec4(x *  _other.x, y *  _other.y, z *  _other.z, w *  _other.w);               }
    public: inline ivec4& operator*=(const ivec4& _other)       {              x *= _other.y; y *= _other.y; z *= _other.z; w *= _other.w ; return *this; }
    public: inline ivec4  operator* (const i32&   _other) const { return ivec4(x *  _other  , y *  _other  , z *  _other  , w *  _other  );               }
    public: inline ivec4& operator*=(const i32&   _other)       {              x *= _other  ; y *= _other  ; z *= _other  ; w *= _other   ; return *this; }

    public: inline ivec4  operator/ (const ivec4& _other) const { return ivec4(x /  _other.x, y /  _other.y, z /  _other.z, w /  _other.w);               }
    public: inline ivec4& operator/=(const ivec4& _other)       {              x /= _other.y; y /= _other.y; z /= _other.z; w /= _other.w ; return *this; }
    public: inline ivec4  operator/ (const i32&   _other) const { return ivec4(x /  _other  , y /  _other  , z /  _other  , w /  _other  );               }
    public: inline ivec4& operator/=(const i32&   _other)       {              x /= _other  ; y /= _other  ; z /= _other  ; w /= _other   ; return *this; }
};