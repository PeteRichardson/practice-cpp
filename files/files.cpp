#include <iostream>
#include <fstream>

int main (int argc, char** argv) {
    if (argc < 2) {
        std::cout << "# usage: files <filename> [<filename>...]" << std::endl;
        return 1;
    }
    // open the stream and create iterators on it
    std::ifstream ifs("foo.txt");
    std::istream_iterator<std::string> begin(ifs), end;
    
    std::for_each(begin, end, [&](std::string token){ 
        std::cout << token << std::endl;
    });
}