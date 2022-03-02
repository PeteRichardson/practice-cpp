#include <iostream>
#include <string>
#include <typeinfo>

using std::cout, std::endl, std::string;

template <typename T> 
void dump(std::ostream& out, T& obj) {
    out << "type: " << typeid(obj).name();
    out << "size: " << sizeof(obj);
}

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

int main(int argc, char** argv) {
    Person pete{"Pete Richardson", 56, 'M'};
    dump(cout, pete);
    cout << pete << endl;
}
