#pragma once

#include <types/fvec2.h>
#include <types/single.h>





struct fvec3
{
    public: f32 x;
    public: f32 y;
    public: f32 z;

    public: inline fvec3(                                               ) : x(0    ), y(0    ), z( 0   ) { }
    public: inline fvec3(const f32   _xyz                               ) : x(_xyz ), y(_xyz ), z(_xyz ) { }
    public: inline fvec3(const fvec2 _xy , const f32   _z               ) : x(_xy.x), y(_xy.y), z(_z   ) { }
    public: inline fvec3(const f32   _x  , const fvec2 _yz              ) : x(_x   ), y(_yz.x), z(_yz.y) { }
    public: inline fvec3(const f32   _x  , const f32   _y , const f32 _z) : x(_x   ), y(_y   ), z(_z   ) { }

    public: inline fvec3  operator+ (const fvec3& _other) const { return fvec3(x +  _other.x, y +  _other.y, z +  _other.z);              }
    public: inline fvec3& operator+=(const fvec3& _other)       {              x += _other.y; y += _other.y; z += _other.z; return *this; }
    public: inline fvec3  operator+ (const f32&   _other) const { return fvec3(x +  _other  , y +  _other  , z +  _other  );              }
    public: inline fvec3& operator+=(const f32&   _other)       {              x += _other  ; y += _other  ; z += _other  ; return *this; }

    public: inline fvec3  operator- (const fvec3& _other) const { return fvec3(x -  _other.x, y -  _other.y, z -  _other.z);              }
    public: inline fvec3& operator-=(const fvec3& _other)       {              x -= _other.y; y -= _other.y; z -= _other.z; return *this; }
    public: inline fvec3  operator- (const f32&   _other) const { return fvec3(x -  _other  , y -  _other  , z -  _other  );              }
    public: inline fvec3& operator-=(const f32&   _other)       {              x -= _other  ; y -= _other  ; z -= _other  ; return *this; }

    public: inline fvec3  operator* (const fvec3& _other) const { return fvec3(x *  _other.x, y *  _other.y, z *  _other.z);              }
    public: inline fvec3& operator*=(const fvec3& _other)       {              x *= _other.y; y *= _other.y; z *= _other.z; return *this; }
    public: inline fvec3  operator* (const f32&   _other) const { return fvec3(x *  _other  , y *  _other  , z *  _other  );              }
    public: inline fvec3& operator*=(const f32&   _other)       {              x *= _other  ; y *= _other  ; z *= _other  ; return *this; }

    public: inline fvec3  operator/ (const fvec3& _other) const { return fvec3(x /  _other.x, y /  _other.y, z /  _other.z);              }
    public: inline fvec3& operator/=(const fvec3& _other)       {              x /= _other.y; y /= _other.y; z /= _other.z; return *this; }
    public: inline fvec3  operator/ (const f32&   _other) const { return fvec3(x /  _other  , y /  _other  , z /  _other  );              }
    public: inline fvec3& operator/=(const f32&   _other)       {              x /= _other  ; y /= _other  ; z /= _other  ; return *this; }
};