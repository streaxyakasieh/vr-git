#pragma once

#include "types/single.h"
#include <exception>
#include <iostream>




inline void Log  (str _message) { std::cout << _message << "\n";                   }
[[noreturn]]
inline void Error(str _message) { std::cerr << _message << "\n"; std::terminate(); }