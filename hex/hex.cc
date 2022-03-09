
#include <iostream>
#include <memory>

#include "dbg.h"
#include "person.h"

using std::cerr, std::endl;

int main(int argc, char** argv) {
    auto pete = std::make_unique<Person>("Pete");

    cerr << memdump(pete) << endl;
    cerr << memdump(*pete) << endl;
}
