#include <iostream>
#include <string>
#include <memory>
#include <array>

using std::cout, std::endl, std::string;

class Person {
public:
    string name_{};
    unsigned int age_{};
    char gender_{};

    Person(string name, unsigned int age, char gender) :
        name_{name}, age_{age}, gender_{gender} {
            cout << "# Created Person(" << name_ << ", " << age_ << ", " << gender_ << ")" << endl;
        }    
};
std::ostream& operator<<(std::ostream& out, Person& p) {
    out << p.name_ << ": age=" << p.age_ << ", gender=" << p.gender_;
    return out;
}

int main(int argc, char** argv) {
    auto pete  = std::make_shared<Person>("Pete", 56, 'M');
    auto wendy = std::make_shared<Person>("Wendy", 55, 'F');
    auto katherine = std::make_shared<Person>("Katherine", 18, 'F');
    auto bella = std::make_shared<Person>("Bella", 8, 'F');

    std::array<std::shared_ptr<Person>, 4> people { pete, wendy, katherine, bella };

    for (auto p: people) {
        cout << *p << endl;
    }
}
