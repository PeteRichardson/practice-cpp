#include <iostream>
#include <random>
#include <string>

std::vector<std::string> words {
    // words.h is generated from pdfs during the build
    #include "words.h"    
};

std::random_device rd{};

std::string RandomPassword() {
    const unsigned int word_count = std::size(words);
    std::string random_digits = std::to_string(rd() % 100 + 100).substr(1);
    return words[rd() % word_count] + "-" + words[rd() % word_count] + random_digits;
}

int main(int argc, char** argv) {
    const unsigned int password_count = 10u;
    for (auto i = 0; i < password_count; i++) {
		std::cout << RandomPassword() << std::endl;
	};
}
