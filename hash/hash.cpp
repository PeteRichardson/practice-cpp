#include <iostream>

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    std::hash<std::string> hash;

    const string message = "Bella";

    cout << message << "--> 0x" << std::hex << hash(message) << endl;
}