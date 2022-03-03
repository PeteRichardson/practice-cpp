#include <iostream>

#include "person.h"

using std::cout, std::endl;

int main(int argc, char** argv) {
    auto pete = Person("pete", 56, 'M');
    cout << pete << endl;
}
