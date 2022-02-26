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
    auto pete  = std::make_unique<Person>("Pete", 56, 'M');
    auto wendy = std::make_unique<Person>("Wendy", 56, 'F');
    auto katherine = std::make_unique<Person>("Katherine", 18, 'F');
    auto bella = std::make_unique<Person>("Bella", 8, 'F');

    std::array<std::unique_ptr<Person>, 4> people;
    people[0] = std::move(pete);
    people[1] = std::move(wendy);
    people[2] = std::move(katherine);
    people[3] = std::move(bella);
    for (auto i = 0; i<=3; i++) {
        cout << *(people[i]) << endl;
    }
}
