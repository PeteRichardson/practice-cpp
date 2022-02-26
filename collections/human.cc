#include "human.h"

#include <iostream>
#include <string>

#include "being.h"

using std::cout, std::endl, std::string;

Human::Human(string name, unsigned int age, char gender, unsigned int leg_count=2, string ss_number="000-00-0000", string phone_number="") :
    Being(name, age, gender, leg_count, ss_number), phone_number_{phone_number} {
    cout << "# Created Human: " << name_ << std::hex << "@" << this << endl;
}

// Copy constructor that logs copies
Human::Human(const Human& rhs) : Being{rhs}, phone_number_{rhs.phone_number_} {
        cout << "# Copying Human " << name_ << std::hex << "@" << this << endl;   
}

Human::~Human() {
    cout << "# Destroyed Human " << name_ << std::hex << "@" << this << endl;
}

std::ostream& Human::print(std::ostream& out) const {
    out << "Human("; dump_fields(out); out << ")";
    return out;
}

std::ostream& Human::dump_fields(std::ostream& out) const {
    Being::dump_fields(out);
    out << ", " << phone_number_;
    return out;
}