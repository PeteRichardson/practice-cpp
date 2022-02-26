#include "animal.h"

#include <iostream>
#include <string>

#include "being.h"

using std::cout, std::endl, std::string;

Animal::Animal(string name, unsigned int age, char gender, unsigned int leg_count=4, string ss_number="111-11-1111", string breed="") :
    Being(name, age, gender, 4, ss_number), breed_{breed} {
    cout << "# Created Animal " << name_ << std::hex << "@" << this << endl;
}

// Copy constructor that logs copies
Animal::Animal(const Animal& rhs) : Being{rhs}, breed_{rhs.breed_} {
        cout << "# Copying Animal " << name_ << std::hex << "@" << this << endl;   
}

Animal::~Animal() {
    cout << "# Destroyed Animal " << name_ << std::hex << "@" << this << endl;
}

std::ostream& Animal::print(std::ostream& out) const {
    out << "Animal("; dump_fields(out); out << ")";
    return out;
}

std::ostream& Animal::dump_fields(std::ostream& out) const {
    Being::dump_fields(out);
    out << ", " << breed_;
    return out;
}