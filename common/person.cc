#include "person.h"

#include <iostream>
#include <string>
#include <typeinfo>

using std::cout, std::endl, std::string;

Person::Person(string name, unsigned int age, char gender, string ssNumber) 
    : name_{name}, age_{age}, gender_{gender}, ssNumber_{ssNumber} {
    // cout << "# Created Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
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
    // cout << "# Deleted Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
}

std::ostream& operator<<(std::ostream& out, Person& p) {
    // out << p.name_ << ": age=" << p.age_ << ", gender=" << p.gender_;
    string gender_str{"person"};
    switch (p.gender_) {
        case 'M': gender_str = "male";
            break;
        case 'F': gender_str = "female";
            break;
        }

    out << p.name_ << " is a " << p.age_ << " year old " << gender_str << '.';
    return out;
}

Person operator"" _person(const char* p, size_t n) {
    return Person(p);
}

// Convenience constructor to create common records with just name:
//  e.g. Person me = Person("Pete")
// Fragile!  since hash is hardcoded, case-sensitive, etc.
//  e.g. Person("pete") returns empty Person object.
//  Probably best to add build step to compute hashes based
//  on some csv file.  This would protect against hash alg changes.
// The whole hashing mess is here because C++ doesn't let you switch
// on strings.   Should just use a big if statement instead :-)
Person::Person(string name) {
    const std::hash<std::string> hash;
    const size_t    Pete_hash       = 0x74b5114960d4dbb5,
                    Wendy_hash      = 0x36b08031605dcf42,
                    Katherine_hash  = 0xde94a097bdb94d96,
                    Bella_hash      = 0x44c5c00799cf77a1;
    name_=name;
    switch (hash(name)) {
        case Pete_hash:         // "Pete"
            age_=56;
            gender_='M';
            ssNumber_="abc-de-fghi";
            break;
        case Wendy_hash:        // "Wendy"
            age_=55;
            gender_='F';
            ssNumber_="xyz-ab-cdef";
            break;
        case Katherine_hash:    // "Katherine"
            age_=18;
            gender_='F';
            ssNumber_="zzz-xx-yyyy";
            break;
        case Bella_hash:        // "Bella"
            age_=7;
            gender_='F';
            this->ssNumber_="cat-03-2014";
            break;
        default:
            age_={};
            gender_={'?'};
            ssNumber_={};
    }
}

string Person::GetSSNumber() {
    return ssNumber_;
}

string Person::ClassName() {
    return typeid(Person).name();
}