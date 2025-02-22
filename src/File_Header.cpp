
#include <File_Header.hpp>

namespace drumstick {

    void
    File_Header::print_self() {
        print("-File_Header-\n* version: {}\n* date_time: ", version);
        for (char& c: date_time) {
            print("{}", c);
        }
        print("\n* row_count (NX): {}\n* column_count (NY): {}\n* level_count (N): {}\n* distance: {}\n* quant_count: {}\n", row_count, column_count, level_count, distance, quant_count);
        print("\n");
    }

}
