
#include <iostream>
#include <format>

namespace drumstick {

constexpr const char* TERMINATE_MESSAGE_FORMAT = R"(
[ERROR]
* File: {}
* Line: {}
* Cond: {}
)";

    void
    terminate(
        const char* file_name,
        int line,
        const char* condition_str,
        const char* message
    ) {
        std::cout << std::format(TERMINATE_MESSAGE_FORMAT, file_name, line, condition_str);
        if (message) {
            std::cout << std::format("* {}\n", message);
        }

        std::terminate();
    }

} // drumstick
