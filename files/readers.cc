#include <iostream>
#include <fstream>
#include "readers.h"

using std::cout, std::endl, std::string;

void readlines(std::ifstream &file) {
    // METHOD 1: using std::getline in a loop
    cout << "# METHOD 1: Reading line by line using std::getline:" << endl;
    string line{};
    while (std::getline(file, line)) {
        cout << line << endl;
    }
}

void readtokens(std::ifstream &file) {
    // METHOD 2:  using istream_iterator<std::string>
    cout << "# METHOD 2: Reading tokens using std::istream_iterator<std::string>:" << endl;
    std::istream_iterator<std::string> begin(file), end;
    std::for_each(begin, end, [&](string token){ 
        cout << token << endl;
    });
}
