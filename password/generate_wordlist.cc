#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>

#include "log.h"
#include "perf.h"

using std::cout, std::string;

std::vector<string> words{};

int main(int argc, char** argv) {
    setup_console_logging(plog::none);

    Timer clock{};
    clock.tick();

    std::set<string> wordset;

    if (argc < 2) {
        PLOGF << "Usage: " << argv[0] << " <filename>";
        std::exit(EXIT_FAILURE);
    }

    string filename = argv[1];
    PLOGI << "Loading " << filename;
    std::ifstream tokenfile(filename);
    if (!tokenfile) {
        PLOGF << "Can't open " << filename;
        std::exit(EXIT_FAILURE);
    }
    string token;
    while (std::getline(tokenfile, token, ' ')) {
        token.erase (std::remove_if(token.begin (), token.end (), ispunct), token.end ());
        token.erase (std::remove_if(token.begin (), token.end (), isdigit), token.end ());
        if (token.length() > 4) {
            token[0] = toupper(token[0]);
            wordset.insert(token.c_str());
            cout <<"\t\"" << token << "\"," << "\n";
        }
    }
    cout << std::flush;

    // convert wordset to vector
    words.reserve (wordset.size ());
    std::copy (wordset.begin (), wordset.end (), std::back_inserter (words));

    PLOGI << "Total words: " << wordset.size();

    clock.tock();
    PLOGI << "Runtime: " << clock.duration().count() << "ms";
}
