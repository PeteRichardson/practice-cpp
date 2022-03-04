#include <iostream>
#include <string>
#include <vector>

#include "being.h"
#include "human.h"
#include "animal.h"

using std::cout, std::endl, std::string;

using Bng_up = std::unique_ptr<Being>;

int main(int argc, char** argv) {

    auto pete = std::make_unique<Being>("Pete Richardson", 56, 'M', 2, "xxx-xx-1234");
    auto wendy = std::make_unique<Human>("Wendy Wilson", 55, 'F', 2, "xxx-xx-5678", "650-218-7915");
    auto bella = std::make_unique<Animal>("Bella", 8, 'F', 4, "zzz-zzz-4321", "Russian Blue");
    cout << endl;

    std::vector<std::unique_ptr<Being>> people{};   // can't use { pete, wendy, bella } because
                                                    // initializer lists always copy, and you 
                                                    // can't copy a unique_ptr.

    people.push_back(std::move(pete));
    people.push_back(std::move(wendy));
    people.push_back(std::move(bella));
    for (const auto &p : people ) {
         cout << *p << endl;
    }
    cout << endl;

}
