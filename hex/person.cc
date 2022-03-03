#include "person.h"

#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

Person::Person(string name, unsigned int age, char gender) :
    name_{name}, age_{age}, gender_{gender} {
    cout << "# Created Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
}

// Copy constructor
Person::Person(const Person& p) :
    name_{p.name_}, age_{p.age_}, gender_{p.gender_} {
    cout << "# Copied Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
}

// Assignment
Person& Person::operator=(const Person& rhs) {
    cout << "# (PRE) Assigned Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
    if (&rhs != this) {
        this->name_ = rhs.name_;
        this->age_ = rhs.age_;
        this->gender_ = rhs.gender_;
    }
    cout << "# (POST) Assigned Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
    return *this;
}  

Person::~Person() {
    cout << "# Deleted Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
}

std::ostream& operator<<(std::ostream& out, Person& p) {
    out << p.name_ << ": age=" << p.age_ << ", gender=" << p.gender_;
    return out;
}