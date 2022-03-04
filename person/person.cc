#include <iostream>
#include <string>
#include <memory>
#include <array>

#include "utils.h"

using std::cout, std::endl, std::string;

class Person {
public:
    string name_{};
    unsigned int age_{};
    char gender_{};

    // Constructor
    Person(string name, unsigned int age, char gender) :
        name_{name}, age_{age}, gender_{gender} {
        cout << "# Created Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
    }

    // Copy constructor
    Person(const Person& p) :
        name_{p.name_}, age_{p.age_}, gender_{p.gender_} {
        cout << "# Copied Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
    }

    // Assignment
    Person& operator=(const Person& rhs) {
        cout << "# (PRE) Assigned Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
       if (&rhs != this) {
            this->name_ = rhs.name_;
            this->age_ = rhs.age_;
            this->gender_ = rhs.gender_;
        }
        cout << "# (POST) Assigned Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
        return *this;
    }  

    // Person(const Person&& p) :
    //     name_{p.name_}, age_{p.age_}, gender_{p.gender_} {
    //     cout << "# RValue-Copied Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
    // }
    // Copy Assignment
    // Person& operator=(const Person& rhs) {
    //     if (&rhs != this) {
    //         this->name_ = rhs.name;
    //         this->age_ = rhs.age;
    //         this->gender_ = rhs.gender;
    //     }
    //     cout << "# Copy-Assigned Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
    //     return *this;
    // }  

    ~Person() {
        cout << "# Deleted Person@"<< this << " (" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
    }
};
std::ostream& operator<<(std::ostream& out, Person& p) {
    out << p.name_ << ": age=" << p.age_ << ", gender=" << p.gender_;
    return out;
}

int main(int argc, char** argv) {
    auto pete  = std::make_unique<Person>("Pete", 56, 'M');
    auto wendy = std::make_unique<Person>("Wendy", 55, 'F');
    auto katherine = std::make_unique<Person>("Katherine", 18, 'F');
    auto bella = std::make_unique<Person>("Bella Hand o'the Queen", 8, 'F');
    Person *george_p = new Person("George", 12, 'M');
    Person joe = Person("Joe", 25,'M');

    cout << "*bella: (size " << sizeof *bella << ")\n" << dbg::memdump(*bella);
    
    cout << ">>>>>>>>>>>" << endl;
    auto george2 = george_p;
    auto george_sp = std::shared_ptr<Person>(george_p);
    auto george3 = george_sp;
    joe = *george_p;
    cout << "<<<<<<<<<<<" << endl;

    std::array<std::unique_ptr<Person>, 4> people{};
    try {
        people.at(0) = std::move(pete);
        people.at(1) = std::move(wendy);
        people.at(2) = std::move(katherine);
        people.at(3) = std::move(bella);
        people.at(4) = std::make_unique<Person>(*george_p);  //Should throw here...
    } catch (const std::out_of_range& e) {
        std::cerr << "# CATCH: I guess we're done! " << e.what() << '\n';
    }
    for (const auto &p: people) {
        cout << *p << endl;
    }
}
