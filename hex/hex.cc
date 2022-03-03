#include <iostream>
#include <memory>

#include "person.h"
#include "utils.h"

using std::cout, std::endl;

int main(int argc, char** argv) {
    auto pete = std::make_unique<Person>("Pete Richardson", 56, 'M');

    cout << dbg::memdump(pete) << endl;
    cout << dbg::memdump(*pete) << endl;
}
