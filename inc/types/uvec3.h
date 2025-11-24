#pragma once

#include <types/uvec2.h>
#include <types/single.h>





struct uvec3
{
    public: u32 x;
    public: u32 y;
    public: u32 z;

    public: inline uvec3(                                               ) : x(0    ), y(0    ), z( 0   ) { }
    public: inline uvec3(const u32   _xyz                               ) : x(_xyz ), y(_xyz ), z(_xyz ) { }
    public: inline uvec3(const uvec2 _xy , const u32   _z               ) : x(_xy.x), y(_xy.y), z(_z   ) { }
    public: inline uvec3(const u32   _x  , const uvec2 _yz              ) : x(_x   ), y(_yz.x), z(_yz.y) { }
    public: inline uvec3(const u32   _x  , const u32   _y , const u32 _z) : x(_x   ), y(_y   ), z(_z   ) { }

    public: inline uvec3  operator+ (const uvec3& _other) const { return uvec3(x +  _other.x, y +  _other.y, z +  _other.z);              }
    public: inline uvec3& operator+=(const uvec3& _other)       {              x += _other.y; y += _other.y; z += _other.z; return *this; }
    public: inline uvec3  operator+ (const u32&   _other) const { return uvec3(x +  _other  , y +  _other  , z +  _other  );              }
    public: inline uvec3& operator+=(const u32&   _other)       {              x += _other  ; y += _other  ; z += _other  ; return *this; }

    public: inline uvec3  operator- (const uvec3& _other) const { return uvec3(x -  _other.x, y -  _other.y, z -  _other.z);              }
    public: inline uvec3& operator-=(const uvec3& _other)       {              x -= _other.y; y -= _other.y; z -= _other.z; return *this; }
    public: inline uvec3  operator- (const u32&   _other) const { return uvec3(x -  _other  , y -  _other  , z -  _other  );              }
    public: inline uvec3& operator-=(const u32&   _other)       {              x -= _other  ; y -= _other  ; z -= _other  ; return *this; }

    public: inline uvec3  operator* (const uvec3& _other) const { return uvec3(x *  _other.x, y *  _other.y, z *  _other.z);              }
    public: inline uvec3& operator*=(const uvec3& _other)       {              x *= _other.y; y *= _other.y; z *= _other.z; return *this; }
    public: inline uvec3  operator* (const u32&   _other) const { return uvec3(x *  _other  , y *  _other  , z *  _other  );              }
    public: inline uvec3& operator*=(const u32&   _other)       {              x *= _other  ; y *= _other  ; z *= _other  ; return *this; }

    public: inline uvec3  operator/ (const uvec3& _other) const { return uvec3(x /  _other.x, y /  _other.y, z /  _other.z);              }
    public: inline uvec3& operator/=(const uvec3& _other)       {              x /= _other.y; y /= _other.y; z /= _other.z; return *this; }
    public: inline uvec3  operator/ (const u32&   _other) const { return uvec3(x /  _other  , y /  _other  , z /  _other  );              }
    public: inline uvec3& operator/=(const u32&   _other)       {              x /= _other  ; y /= _other  ; z /= _other  ; return *this; }
};