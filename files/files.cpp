#include <iostream>
#include <fstream>
#include "readers.h"

using std::cout, std::endl, std::string;

int main (int argc, char** argv) {
    if (argc < 2) {
        cout << "# usage: files <filename>" << endl;
        return 1;
    }

    string filename {argv[1]};
    std::ifstream file(filename);
    if (!file.is_open()) {
        cout << "# ERROR: Unable to open " << filename << endl;
        return 2;
    }

    readlines(file);

    cout << endl;
    file.clear();  // need to reset the stream before METHOD 2
    file.seekg(0);

    readtokens(file);

    file.close();

 }