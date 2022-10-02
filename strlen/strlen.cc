// Investigate the highly optimized gcc strlen algorithm
// for deciding if a word has any zero bytes in it
// See: https://github.com/lattera/glibc/blob/master/string/strlen.c
// and  https://www.quora.com/As-a-software-engineer-whats-the-most-ingenious-line-of-code-youve-seen

#include <iostream>
#include <iomanip>

using std::cout, std::bitset;

int main(int argc, char** argv) {
    uint16_t himagic = 0x8080;   // use 16bit word, but can extend for 32, 64, etc
    uint16_t lomagic = 0x0101;

    for (int val = 0; val < 65536; val++) {
        // Here's the magic algorithm!
        // uint16_t result = (val - lomagic) & ~val & himagic;
        // result should be non-zero if one or more bytes in val is zero
        
        // Instead of calculating result all at once, lets
        // break it into intermediate resutls so we can
        // show each part of the calculation to look for patterns and exceptions
        uint16_t valminuslo = val - lomagic;
        uint16_t andnotval = valminuslo & ~val;
        uint16_t result = andnotval & himagic;

        if (result != 0) {  // for now, show only values that the alg says have a zero byte
            cout << "Ox" << std::hex << std::setw(4) << std::setfill('0') << val << " -> ";
            cout << bitset<16>(val).to_string() << " -> ";
            cout << bitset<16>(valminuslo).to_string() << " -> ";
            cout << bitset<16>(andnotval).to_string() << " -> ";
            cout << (std::bitset<16>(result)).to_string() << std::endl;
        }
    }
}
