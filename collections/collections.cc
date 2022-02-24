#include <iostream>
#include <string>
#include <set>

using std::cout, std::endl;

using strings = std::set<std::string>;

int main(int argc, char** argv) {
    strings people { "Pete", "Wendy", "Katherine"};
    strings pets { "Bella", "Newton", "Zoe"};

    strings family {};
    family.merge(people);
    family.merge(pets);

    for (auto &s: family) {
        cout << s << endl;
    }

    cout << family.size() << endl;

    cout << "Bella in the set? " << family.contains("Bella") << endl;

}
