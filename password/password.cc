#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "log.h"
#include "perf.h"

using std::cout, std::string;

std::vector<string> words{};

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

void LoadWords() {
// For each pdf in a list (or folder?), read all the text using podofotxtextract tool
// (brew install podofo)
// tokenize the text and add any sufficiently complex words to the set wordset.
// That removes duplicates.
// Then copy that set into a vector, so we can randomly pick words from it

    std::set<string> wordset;

    std::vector<string> filenames = {
        "/Users/pete/projects/cpp/password/Origin_of_Species.pdf",
        "/Users/pete/projects/cpp/password/virgil-aeneid-trans-fagles-penguin-2006-1.pdf"
    };
    for (auto & filename: filenames) {
        PLOGI << "Loading " << filename;
        string cmd = "podofotxtextract " + filename + " 2>/dev/null";
        string txt = exec(cmd.c_str());
        PLOGI << " - Read " << txt.length() << " characters.";

        // tokenize line and add sufficiently complex words to wordset
        // std::istringstream s(txt);
        std::istringstream s(txt);
        string token;
        while (std::getline(s, token, ' ')) {
            if ((token.length() > 4) & (token[4] != '0') & (!isdigit(token[0]))) {
                token.erase (std::remove_if(token.begin (), token.end (), ispunct), token.end ());
                token[0] = toupper(token[0]);
                wordset.insert(token.c_str());
                // cout << token << "\n";
            }
        }
        cout << std::flush;
    }

    // convert wordset to vector
    words.reserve (wordset.size ());
    std::copy (wordset.begin (), wordset.end (), std::back_inserter (words));
}

std::random_device rd{};

string RandomPassword() {
    const unsigned int word_count = std::size(words);
    string random_digits = std::to_string(rd() % 100 + 100).substr(1);
    return words[rd() % word_count] + "-" + words[rd() % word_count] + random_digits;
}

int main(int argc, char** argv) {
    setup_console_logging(plog::none);

    perf::Timer clock{};
    clock.tick();
    LoadWords();
    clock.tock();
    PLOGI << "Setup time: " << clock.duration().count() << "ms";

    const unsigned int password_count = 10u;
    for (auto i = 0; i < password_count; i++) {
		std::cout << RandomPassword() << std::endl;
	};
}
