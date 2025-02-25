
#include <drumstick/Image.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

namespace drumstick {

    Image::Image(int width, int height)
    : width(width), height(height), data(new u8[width * height * 4]) {}

    Image::Image(int width, int height, u8* source)
    : width(width), height(height), data(new u8[width * height * 3]) {
        for (int i = 0; i < 3; ++i) {
            memcpy(data+(i*(width*height)), source, width*height);
        }
    }

    Image::~Image() {
        /*
            @memory: no stall, leak it
        */
        // delete[] data;
    }

    int
    Image::area() {
        return width * height;
    }

    int
    Image::size() {
        return width * height * 4;
    }

    u32&
    Image::operator[](int index) {
        u32* pixel = reinterpret_cast<u32*>(&(data[index * 4]));
        return *pixel;
    }

    void
    Image::write_to_disk(const std::string& image_path) {
        stbi_write_png(
            image_path.c_str(),
            width,
            height,
            3,
            (void*)data,
            width*3
        );
    }

}
