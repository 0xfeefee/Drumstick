
#pragma once

namespace drumstick {

    class Data_View;

    /*
        A chunk of binary data, to which we can take views.
    */
    struct Data {
        const int       byte_count;
        const u8* const ptr;

        explicit
        Data(int byte_count, u8* ptr);

        ~Data();

        Data_View
        view(int start_pos);
    };

    /*
        Non-owning pointer to binary data, used to traverse it and convert it to useful things.
    */
    class Data_View {
        int byte_count;
        u8* ptr;

    public:
        explicit Data_View(const Data& data, int start = 0);

        void
        move(int amount);

        u8
        operator[](int index);

        template <typename T>
        T
        get() {
            T   value;
            int size = static_cast<int>(sizeof(T));

            memcpy(&value, ptr, size);
            move(size);

            return value;
        }
    };

}
