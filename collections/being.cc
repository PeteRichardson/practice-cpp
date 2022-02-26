#include "being.h"

#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

Being::Being(string name, unsigned int age, char gender, unsigned int leg_count={}, string ss_number={"000-00-0000"}) :
    name_{name}, age_{age}, gender_{gender}, leg_count_{leg_count}, ss_number_{ss_number} {
    cout << "# Created Being " << name_ << std::hex << "@" << this << endl;
}

// Copy constructor that logs copies
Being::Being(const Being& rhs) : name_{rhs.name_}, age_{rhs.age_}, gender_{rhs.gender_},
    leg_count_{rhs.leg_count_}, ss_number_{rhs.ss_number_} {
        cout << "# Copying Being " << name_ << std::hex << "@" << this << endl;   
}

Being::~Being() {
    cout << "# Destroyed Being " << name_ << std::hex << "@" << this << endl;
}

std::ostream& Being::print(std::ostream& out) const {
    out << "Being("; dump_fields(out); out << ")";
    return out;
}

std::ostream& Being::dump_fields(std::ostream& out) const {
    out << name_ << ", " << age_ << ", " << gender_ << ", " << leg_count_ << ", " << ss_number_;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Being& b) {
    return b.print(out);
}