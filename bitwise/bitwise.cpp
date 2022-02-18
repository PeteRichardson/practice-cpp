#include <iostream>
#include <bitset>
#include "utils.h"

unsigned long long byte1_mask { 0xFFULL << (0 * 8) };
unsigned long long byte2_mask { 0xFFULL << (1 * 8) };
unsigned long long byte3_mask { 0xFFULL << (2 * 8)  };
unsigned long long byte4_mask { 0xFFULL << (3 * 8)  };
unsigned long long byte5_mask { 0xFFULL << (4 * 8)  };
unsigned long long byte6_mask { 0xFFULL << (5 * 8)  };
unsigned long long byte7_mask { 0xFFULL << (6 * 8)  };
unsigned long long byte8_mask { 0xFFULL << (7 * 8)  };
unsigned long long value { 0x1234567812345678ULL};

int main(int argc, char** argv) {
    log("Hello, Bitwise!");

    std::cout << "value      = " << std::bitset<64>{value} << std::endl;
    std::cout << "byte1_mask = " << std::bitset<64>{byte1_mask} << std::endl;
    std::cout << "byte2_mask = " << std::bitset<64>{byte2_mask} << std::endl;
    std::cout << "byte3_mask = " << std::bitset<64>{byte3_mask} << std::endl;
    std::cout << "byte4_mask = " << std::bitset<64>{byte4_mask} << std::endl;
    std::cout << "byte5_mask = " << std::bitset<64>{byte5_mask} << std::endl;
    std::cout << "byte6_mask = " << std::bitset<64>{byte6_mask} << std::endl;
    std::cout << "byte7_mask = " << std::bitset<64>{byte7_mask} << std::endl;
    std::cout << "byte8_mask = " << std::bitset<64>{byte8_mask} << std::endl;
    std::cout << "-----------------------------------------------------------------------------" << std::endl;

    std::cout << "result     = " << std::bitset<64>{value & byte1_mask} << std::endl;
    std::cout << "result     = " << std::bitset<64>{value & byte2_mask} << std::endl;
    std::cout << "result     = " << std::bitset<64>{value & byte3_mask} << std::endl;
    std::cout << "result     = " << std::bitset<64>{value & byte4_mask} << std::endl;
    std::cout << "result     = " << std::bitset<64>{value & byte5_mask} << std::endl;
    std::cout << "result     = " << std::bitset<64>{value & byte6_mask} << std::endl;
    std::cout << "result     = " << std::bitset<64>{value & byte7_mask} << std::endl;
    std::cout << "result     = " << std::bitset<64>{value & byte8_mask} << std::endl;


    log("Goodbye, Bitwise!");
}