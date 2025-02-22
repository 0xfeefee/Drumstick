
#include <string>
#include <fstream>

#include <Data.hpp>
#include <File_Header.hpp>
using namespace drumstick;


static inline Data
read_entire_file(const std::string& file_name) {
    EXPECT(file_name.size() > 0);

    std::ifstream input_file(file_name, std::ios::binary | std::ios::ate);
    EXPECT(input_file.is_open());

    int size = input_file.tellg();
    u8* ptr  = new u8[size];

    input_file.seekg(0, std::ios::beg);
    input_file.read(reinterpret_cast<char*>(ptr), size);

    return Data(size, ptr);
}

int
main(int, char*[]) {
    Data data = read_entire_file("data/1706221600.29"); {
        Data_View view = data.view(0);

        File_Header* header = view.get_view<File_Header>();
        header->print_self();

        s16* quantisation_levels = view.get_view_array<s16>(header->quant_count);
        for (int i = 0; i < header->quant_count; ++i) {
            print("{}, ", quantisation_levels[i]);
        }

        print("\n");

        std::vector<u8*> levels;
        levels.reserve(header->level_count);

        for (int i = 0; i < header->level_count; ++i) {
            u8* pixels = view.get_view_array<u8>(header->column_count*header->row_count);
            levels.push_back(pixels);
        }

        /*
            We have the exact number of bytes, since incrementing the pointer will break an
            assert if commented out:
        */
        // view.move(1);
    }

    return 0;
}

/*==
-File_Header-
* version: 1
* date_time: 22 Jun 2007 16:00
* row_count (NX): 824
* column_count (NY): 648
* level_count (N): 16
* distance: 1000
* quant_count: 14
==*/
