#include <iostream>
#include <fstream>

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

    // METHOD 1: using std::getline in a loop
    cout << "# METHOD 1: Reading line by line using std::getline:" << endl;
    string line{};
    while (std::getline(file, line)) {
        cout << line << endl;
    }

    cout << endl;
    file.clear();  // need to reset the stream before METHOD 2
    file.seekg(0);

    // METHOD 2:  using istream_iterator<std::string>
    //            Note that this returns tokens, not lines
    cout << "# METHOD 2: Reading tokens using std::istream_iterator<std::string>:" << endl;
    std::istream_iterator<std::string> begin(file), end;
    std::for_each(begin, end, [&](string token){ 
        cout << token << endl;
    });

    file.close();

 }