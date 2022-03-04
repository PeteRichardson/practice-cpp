#include <iostream>
#include <memory>

#include "dbg.h"

using std::cout, std::endl;

#pragma pack(0)
#include "person.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wignored-pragmas"
#pragma options align=reset
#pragma clang diagnostic pop

int main(int argc, char** argv) {
    //Person pete{"Pete Richardson", 56, 'M'};
    auto pete = std::make_unique<Person>("Pete Richardson", 56, 'M');
    auto wendy = std::make_unique<Person>("Wendy Wilson", 55, 'F');
    cout << "*pete\n" << dbg::memdump(*pete) << '\n';
    cout << "*wendy\n" << dbg::memdump(*wendy) << endl;
}
