#include <iostream>
#include <fstream>

int main (int argc, char** argv) {
    if (argc < 2) {
        std::cout << "# usage: files <filename>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (file.is_open()) {
    
        // METHOD 1: using std::getline in a loop
        std::string line{};
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.clear();  // need to reset the stream before METHOD 2
        file.seekg(0);

        // METHOD 2:  using istream_iterator<std::string>
        //            Note that this returns tokens, not lines
        std::istream_iterator<std::string> begin(file), end;
        std::for_each(begin, end, [&](std::string token){ 
            std::cout << token << std::endl;
        });

    }
    file.close();


 }