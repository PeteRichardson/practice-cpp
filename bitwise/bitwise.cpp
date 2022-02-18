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
        // print mask bits with ' 's instead of '0's.
        std::string mask_str { Bits{mask}.to_string() };
        std::replace(mask_str.begin(), mask_str.end(), '0', ' ');
        std::cout << "byte" << byte << " mask = " << mask_str << std::endl;

        // print result bits (hide 0's outside the mask area)
        std::string result { Bits{value & mask}.to_string() };
        // - replace prefix... i.e. beginning of string up to masked area
        //   (remember: string::replace takes a start & count, not a start & end!)
        auto const prefix_end = (8-byte) * 8;     // position right before masked area
        std::string const prefix(prefix_end, ' ');
        result.replace(0, prefix.length(), prefix);
        
        // - replace suffix... i.e. chars after mask up to end of string
        auto const suffix_start = prefix_end + 8; // position right after masked area
        std::string const suffix(64 - suffix_start, ' ');
        result.replace(suffix_start, suffix.length(), suffix);
        std::cout << "          -> " << result << std::endl;

        mask <<= 8;
    }
    std::cout << "value      = " << Bits{value} << std::endl;
 
    log("Goodbye, Bitwise!");
}