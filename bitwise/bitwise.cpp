#include <iostream>
#include <bitset>
#include "utils.h"

unsigned long long value { 0x1234567812345678ULL};

int main(int argc, char** argv) {
    log("Hello, Bitwise!");

    std::cout << "value      = " << std::bitset<64>{value} << std::endl;

    auto mask { 0xFFULL };
    for (auto byte {1}; byte < 9; byte++ ) {
        std::cout << "byte" << byte << " mask = " << std::bitset<64>{mask} << std::endl;
        std::cout << "          -> " << std::bitset<64>{value & mask} << std::endl;
        mask <<= 8;
    }
 
    log("Goodbye, Bitwise!");
}