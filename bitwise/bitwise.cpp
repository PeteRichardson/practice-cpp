#include <iostream>
#include <bitset>
#include "utils.h"

typedef std::bitset<64> Bits;

unsigned long long value { 0x1234567812345678ULL};

int main(int argc, char** argv) {
    log("Hello, Bitwise!");

    std::cout << "value      = " << Bits{value} << std::endl;

    auto mask { 0xFFULL };
    for (auto byte {1}; byte < 9; byte++ ) {
        std::string mask_str { Bits{mask}.to_string() };
        std::replace(mask_str.begin(), mask_str.end(), '0', ' ');
        std::cout << "byte" << byte << " mask = " << mask_str << std::endl;
        std::string result { Bits{value & mask}.to_string() };
        auto prefix_length = (8-byte) * 8;
        std::string prefix(prefix_length, ' ');
        auto len = 64 - (prefix_length + 8);
        std::string suffix(len, ' ');
        result.replace(0, prefix_length, prefix);
        result.replace(prefix_length+8, 64-prefix_length+8, suffix);
        std::cout << "          -> " << result << std::endl;
        mask <<= 8;
    }
    std::cout << "value      = " << Bits{value} << std::endl;
 
    log("Goodbye, Bitwise!");
}