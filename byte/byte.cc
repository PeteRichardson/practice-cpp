#include <cstddef>
#include <iostream>
#include <fmt/core.h>

int main(int argc, char*argv[]) {
    std::byte b{0x4B};

    fmt::print("The byte is 0x{0:X}.\n", b);
}