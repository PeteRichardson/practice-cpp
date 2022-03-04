#include <iostream>
#include <memory>

#include "utils.h"
#include "person.h"

using std::cout, std::endl;

int main(int argc, char** argv) {
    auto pete = std::make_unique<Person>("Pete");

    cout << dbg::memdump(pete) << endl;
    cout << dbg::memdump(*pete) << endl;
}
