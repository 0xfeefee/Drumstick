
#pragma once
#include <drumstick/Data.hpp>

namespace drumstick {

    /*
        4 channel RGBA image assumed.
    */
    struct Image {
        s16 width;
        s16 height;
        u8* data;

        Image(int width, int height);
        Image(int width, int height, u8* data, const std::vector<s16> quantization_levels);
        ~Image();

        int
        size();

        int
        area();

        u32&
        operator[](int index);

        void
        write_to_disk(const std::string& image_path);
    };

}