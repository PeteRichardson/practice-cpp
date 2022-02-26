#include <iostream>
#include <string>
#include <vector>

#include "being.h"
#include "human.h"
#include "animal.h"

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {

    auto pete = std::make_shared<Being>("Pete Richardson", 56, 'M', 2, "xxx-xx-1234");
    auto wendy = std::make_shared<Human>("Wendy Wilson", 55, 'F', 2, "xxx-xx-5678", "650-218-7915");
    auto bella = std::make_shared<Animal>("Bella", 8, 'F', 4, "zzz-zzz-4321", "Russian Blue");
    cout << endl;

    std::vector<std::shared_ptr<Being>> people { pete, wendy, bella };
    for (auto p: people ) {
        cout << *p << endl;
    }
    cout << endl;

}
