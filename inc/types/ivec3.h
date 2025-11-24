#pragma once

#include <types/ivec2.h>
#include <types/single.h>





struct ivec3
{
    public: i32 x;
    public: i32 y;
    public: i32 z;

    public: inline ivec3(                                               ) : x(0    ), y(0    ), z( 0   ) { }
    public: inline ivec3(const i32   _xyz                               ) : x(_xyz ), y(_xyz ), z(_xyz ) { }
    public: inline ivec3(const ivec2 _xy , const i32   _z               ) : x(_xy.x), y(_xy.y), z(_z   ) { }
    public: inline ivec3(const i32   _x  , const ivec2 _yz              ) : x(_x   ), y(_yz.x), z(_yz.y) { }
    public: inline ivec3(const i32   _x  , const i32   _y , const i32 _z) : x(_x   ), y(_y   ), z(_z   ) { }

    public: inline ivec3  operator+ (const ivec3& _other) const { return ivec3(x +  _other.x, y +  _other.y, z +  _other.z);              }
    public: inline ivec3& operator+=(const ivec3& _other)       {              x += _other.y; y += _other.y; z += _other.z; return *this; }
    public: inline ivec3  operator+ (const i32&   _other) const { return ivec3(x +  _other  , y +  _other  , z +  _other  );              }
    public: inline ivec3& operator+=(const i32&   _other)       {              x += _other  ; y += _other  ; z += _other  ; return *this; }

    public: inline ivec3  operator- (const ivec3& _other) const { return ivec3(x -  _other.x, y -  _other.y, z -  _other.z);              }
    public: inline ivec3& operator-=(const ivec3& _other)       {              x -= _other.y; y -= _other.y; z -= _other.z; return *this; }
    public: inline ivec3  operator- (const i32&   _other) const { return ivec3(x -  _other  , y -  _other  , z -  _other  );              }
    public: inline ivec3& operator-=(const i32&   _other)       {              x -= _other  ; y -= _other  ; z -= _other  ; return *this; }

    public: inline ivec3  operator* (const ivec3& _other) const { return ivec3(x *  _other.x, y *  _other.y, z *  _other.z);              }
    public: inline ivec3& operator*=(const ivec3& _other)       {              x *= _other.y; y *= _other.y; z *= _other.z; return *this; }
    public: inline ivec3  operator* (const i32&   _other) const { return ivec3(x *  _other  , y *  _other  , z *  _other  );              }
    public: inline ivec3& operator*=(const i32&   _other)       {              x *= _other  ; y *= _other  ; z *= _other  ; return *this; }

    public: inline ivec3  operator/ (const ivec3& _other) const { return ivec3(x /  _other.x, y /  _other.y, z /  _other.z);              }
    public: inline ivec3& operator/=(const ivec3& _other)       {              x /= _other.y; y /= _other.y; z /= _other.z; return *this; }
    public: inline ivec3  operator/ (const i32&   _other) const { return ivec3(x /  _other  , y /  _other  , z /  _other  );              }
    public: inline ivec3& operator/=(const i32&   _other)       {              x /= _other  ; y /= _other  ; z /= _other  ; return *this; }
};