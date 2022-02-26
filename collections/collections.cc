#include <iostream>
#include <string>
#include <vector>

#include "being.h"
#include "human.h"
#include "animal.h"

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    Being pete{"Pete Richardson", 56, 'M', 2, "xxx-xx-1234"};
    Human wendy{"Wendy Wilson", 55, 'F', 2, "xxx-xx-5678", "650-218-7915"};
    Animal bella{"Bella", 8, 'F', 4, "zzz-zzz-4321", "Russian Blue"};
    cout << endl;

    std::vector<Being> people { std::move(pete), std::move(wendy), std::move(bella) };
    for (Being p: people ) {
        cout << p << endl;
    }

}
