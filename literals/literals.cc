#include <iostream>
#include <vector>

using std::cout, std::endl, std::string;

struct Person {
    string name {};
    int age {};
    char gender {};
};

int main(int argc, char** argv) {
    const char* family_names[] { "Peter", "Wendy", "Katherine", "Bella"};

    string some_name = "Wendy";

    std::vector<Person> peeps {};

    Person wendy;
    wendy.name = some_name;
    wendy.age = 55;
    wendy.gender = 'F';

    peeps.push_back(wendy);

    cout << "wendy.age = " << wendy.age << endl;
    cout << "wendy.name = " << wendy.name << endl;
    cout << "wendy.gender = " << wendy.gender << endl;
    cout << "length(name) = " << wendy.name.length() << endl;

    cout << endl << "length(peeps) = " << peeps.size() << endl;
    cout << "length(first) = " << peeps.front().name.length() << endl;
}

