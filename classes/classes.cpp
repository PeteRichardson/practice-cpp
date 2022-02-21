#include <iostream>

using std::cout, std::endl, std::string;

class Person {
public:
    string name {};
    unsigned int age {};
    char gender {};

    Person(string name, unsigned int age, char gender, string ssNumber);
    Person() {};
    string GetSSNumber();
    static string ClassName();

private:
    string ssNumber {};
};

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

int main(int argc, char** argv) {

    auto pete { Person("Peter", 56, 'M', "123-45-6789") };

    cout << pete.GetSSNumber() << endl;
    cout << Person::ClassName() << endl;
}