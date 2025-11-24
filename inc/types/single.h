#pragma once

// Make dedicated solution for std-libraries.
#include <cstdint>
#include <string>




using i08     = int8_t;
using i16     = int16_t;
using i32     = int32_t;
using i64     = int64_t;

using u08     = uint8_t;
using u16     = uint16_t;
using u32     = uint32_t;
using u64     = uint64_t;

using f32     = float;
using d64     = double;

using ichar08 = char;
using ichar16 = char16_t;
using ichar32 = char32_t;

using uchar08 = unsigned char;

using str     = std::string;

#define i08MIN INT8_MIN;
#define i16MIN INT16_MIN;
#define i32MIN INT32_MIN;
#define i64MIN INT64_MIN;

#define i08MAX INT8_MAX;
#define i16MAX INT16_MAX;
#define i32MAX INT32_MAX;
#define i64MAX INT64_MAX;

#define u08MAX UINT8_MAX;
#define u16MAX UINT16_MAX;
#define u32MAX UINT32_MAX;
#define u64MAX UINT64_MAX;