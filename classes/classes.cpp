#include <iostream>
#include "Person.h"

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    auto pete { Person("Peter", 56, 'M', "123-45-6789") };
    cout << pete.GetSSNumber() << endl;
    cout << Person::ClassName() << endl;
}