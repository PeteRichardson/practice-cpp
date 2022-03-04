#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

#include "utils.h"

using std::cout, std::endl, std::string;

#pragma pack(0)
#include "person.h"
#pragma options align=reset

int main(int argc, char** argv) {
    //Person pete{"Pete Richardson", 56, 'M'};
    auto pete = std::make_unique<Person>("Pete Richardson", 56, 'M');
    auto wendy = std::make_unique<Person>("Wendy Wilson", 55, 'F');
    cout << "*pete\n" << dbg::memdump(*pete) << '\n';
    cout << "*wendy\n" << dbg::memdump(*wendy) << endl;
}
