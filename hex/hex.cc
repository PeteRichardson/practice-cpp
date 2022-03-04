#include <any>
#include <iostream>
#include <memory>

#include "utils.h"
#include "person.h"

using std::cerr, std::endl;

int main(int argc, char** argv) {
    auto pete = std::make_unique<Person>("Pete");

    dbg::dump(cerr, "pete", pete);
    dbg::dump(cerr, "*pete", *pete);
}
