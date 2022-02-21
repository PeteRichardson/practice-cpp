#include "Person.h"

#include <iostream>
using std::cout, std::endl, std::string;

Person::Person(string name, unsigned int age, char gender, string ssNumber) 
    : name{name}, age{age}, gender{gender}, ssNumber{ssNumber} {
    cout << "Constructor called for " << this->name << endl;
}

string Person::GetSSNumber() {
    return this->ssNumber;
}

string Person::ClassName() {
    return "Parson!";
}
