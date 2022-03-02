#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

class Person {
public:
    string name_{};
    unsigned int age_{};
    char gender_{};

    Person(string name, unsigned int age, char gender) : name_{name}, age_{age}, gender_{gender} {
        //cout << "# Created Person " << name_ << '\n';
    }

    // ~Person() {
    //     cout << "# Destroyed Person " << name_ << '\n';
    // }


    friend std::ostream& operator<<(std::ostream& out, Person& p) {
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
};


Person operator"" _person(const char* p, size_t n) {
    string name {p};
    if (name == "Pete") {
            return Person(name, 56, 'M');
    }
    if (name == "Wendy") {
            return Person(name, 55, 'F');
    }
    if (name == "Katherine") {
            return Person(name, 18, 'F');
    }
    // Don't recognize the literal...
    cout << "# Warning:  I don't know who '" << p << "' is." << endl;
    return Person(p,0,'?');
}

int main(int argc, char** argv) {
    Person pete { "Pete", 56, 'M'};
    cout << pete << endl;

    Person wendy = "Wendy"_person;
    cout << wendy << endl;

    Person ian = "Ian"_person;
    cout << ian << endl;
}
