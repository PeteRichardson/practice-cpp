#include <iostream>
#include <common/person.h>

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "# usage: classes <person_name>" << endl;
        exit(1);
    }
    auto entity { Person(argv[1]) };
    cout << entity.GetSSNumber() << endl;
    cout << Person::ClassName() << endl;
}