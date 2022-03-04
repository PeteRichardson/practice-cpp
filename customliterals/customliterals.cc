#include <iostream>
#include <string>

#include "person.h"

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    Person pete { "Pete", 56, 'M'};
    cout << pete << endl;

    auto wendy = "Wendy"_person;
    cout << wendy << endl;

    auto wendy2 = Person("Wendy");
    cout << wendy2 << endl;

    auto ian = "Ian"_person;
    cout << ian << endl;
}
