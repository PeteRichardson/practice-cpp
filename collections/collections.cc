#include <iostream>
#include <string>
#include <vector>


using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    std::vector<string> vec { "Pete", "Wendy", "Katherine", "Bella" };

    for (const string &s: vec) {
        cout << s << endl;
    }
}
