// utils.cpp

#include "utils.h"

#include <iomanip>

void log(std::string str) {
    std::cout << "# " << str << std::endl;
}

std::ostream& hex64(std::ostream& o) {
    return o << std::setfill('.') << std::setw(16) << std::hex << std::uppercase << std::noshowbase;
}