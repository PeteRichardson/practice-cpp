#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

#include "utils.h"

using std::cout, std::endl, std::string;

#pragma pack(0)
class Person {
public:
    string name_{};
    unsigned int age_{};
    char gender_{};

    Person(string name, unsigned int age, char gender) : name_{name}, age_{age}, gender_{gender} {
        cout << "# Created Person@" << this << "(name: "<< name_ << ")" << endl;
    }

    friend std::ostream& operator<<(std::ostream& out, Person& p) {
        out << "Person(" << p.name_ << "," << p.age_ << "," << p.gender_ << ")";
        return out;
    }
};
#pragma options align=reset

int main(int argc, char** argv) {
    //Person pete{"Pete Richardson", 56, 'M'};
    auto pete = std::make_shared<Person>("Pete Richardson", 56, 'M');
    auto wendy = std::make_shared<Person>("Wendy Wilson", 55, 'F');
    cout << "*pete\n" << dbg::memdump(*pete) << '\n';
    cout << "*wendy\n" << dbg::memdump(*wendy) << endl;
}
