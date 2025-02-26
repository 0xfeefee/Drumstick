
#include <drumstick/Data.hpp>
#include <drumstick/File_Header.hpp>
#include <drumstick/Coordinate.hpp>
#include <drumstick/Image.hpp>
using namespace drumstick;

int
main(int, char*[]) {
    // Initialize to referece values given:
    Projection projection(8.194, 50.437, 0, 0, 1018.18, 1018.18);

    Data data = Data::from_file("data/1706221600.29"); {
        Data_View view = data.view(0);

        File_Header* header = view.get_view<File_Header>();
        header->print_self();

        s16* quantisation_levels = view.get_view_array<s16>(header->quant_count);
        for (int i = 0; i < header->quant_count; ++i) {
            print("{}, ", quantisation_levels[i]);
        }

        print("\n");

        // Levels:
        std::vector<u8*> levels;
        levels.reserve(header->level_count);

        for (int i = 0; i < header->level_count; ++i) {
            u8* pixels = view.get_view_array<u8>(header->column_count * header->row_count);
            levels.push_back(pixels);
        }

        int image_size = header->column_count * header->row_count;
        for (int l = 0; l < levels.size(); ++l) {
            u8* level = levels[l];
            Image image(header->column_count, header->row_count);

            for (int i = 0; i < image_size; ++i) {
                u8 pixel = level[i] * 100;
                // s16 q = quantisation_levels[pixel];

                image[i] = pixel | pixel << 8 | pixel << 16 | 0xFF << 24;
            }
            image.write_to_disk(std::format("levels/level_{:02d}.png", l));
        }

        /*
            We have the exact number of bytes, since incrementing the pointer will break an
            assert if commented out:
        */
        // view.move(1);

        /*
            Generate coordinates:
        */
        std::vector<Coordinate> coordinates;
        coordinates.reserve(header->column_count * header->row_count);

        for (int y = 0; y < header->row_count; ++y) {
            for (int x = 0; x < header->column_count; ++x) {
                coordinates.push_back(projection.coordinate_from_grid_position(y, x));
            }
        }
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
