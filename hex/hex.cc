
#include <iostream>
#include <memory>

#include "dbg.h"
#include "person.h"

using std::cerr, std::endl;

int main(int argc, char** argv) {
    auto pete = std::make_unique<Person>("Pete");

    cerr << dbg::memdump(pete) << endl;
    cerr << dbg::memdump(*pete) << endl;
    // dump(cerr, "pete", pete);
    // dump(cerr, "*pete", *pete);
}
