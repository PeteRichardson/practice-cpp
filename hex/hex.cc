#include <iostream>
#include <memory>

#include "person.h"
#include "hexdump.h"

using std::cout, std::endl;

int main(int argc, char** argv) {
    auto pete = std::make_unique<Person>("pete", 56, 'M');
    hexdump(cout, *pete, "pete");
    cout << "\n----------------------------------\n";
    dump(cout, *pete, "pete");
}
