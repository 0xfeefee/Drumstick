
#pragma once
#include <iostream> // IWYU pragma: keep
#include <format>   // IWYU pragma: keep
#include <vector>   // IWYU pragma: keep
#include <string>   // IWYU pragma: keep


typedef uint8_t  u8;
typedef int16_t  s16;
typedef float    f32;

#define EXPECT(condition, ...)   if (!(condition)) \
    drumstick::terminate(__FILE__, __LINE__, #condition, __VA_ARGS__)
#define print(fmt, ...) std::cout << std::format(fmt, __VA_ARGS__);

namespace drumstick {

    /*
        Print out the caller location and terminate the application.
    */
    void
    terminate(
        const char* file_name,
        int line,
        const char* condition_str,
        const char* message = nullptr
    );

}
