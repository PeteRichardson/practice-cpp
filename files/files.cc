#include <iostream>
#include <fstream>
#include <thread>

#include "readers.h"
#include "perf.h"

using std::cout, std::endl, std::string;

int main (int argc, char** argv) {
    if (argc < 2) {
        cout << "# usage: files <filename>" << endl;
        return 1;
    }
    Timer clock;

    string filename {argv[1]};
    std::ifstream file(filename);
    if (!file.is_open()) {
        cout << "# ERROR: Unable to open " << filename << endl;
        return 2;
    }

    clock.tick();
    readlines(file);
    clock.tock();
    cout << "# Runtime: " << clock.duration().count() << "ms" << endl;

    cout << endl;
    file.clear();  // need to reset the stream before METHOD 2
    file.seekg(0);

    clock.tick();
    readtokens(file);
    clock.tock();
    cout << "# Runtime: " << clock.duration().count() << "ms" << endl;

    file.close();

 }