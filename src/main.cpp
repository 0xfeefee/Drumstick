
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
    Data data          = read_entire_file("data/1706221600.29");
    Data_View view     = data.view(0);
    File_Header header = view.get<File_Header>();
    header.print_self();
    return 0;
}
