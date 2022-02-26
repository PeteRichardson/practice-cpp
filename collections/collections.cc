#include <iostream>
#include <string>

#include "being.h"
#include "human.h"
#include "animal.h"

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    Being pete{"Pete Richardson", 56, 'M', 2, "xxx-xx-1234"};
    Human wendy{"Wendy Wilson", 55, 'F', 2, "xxx-xx-5678", "650-218-7915"};
    Animal bella{"Bella", 8, 'F', 4, "zzz-zzz-4321", "Russian Blue"};
    cout << endl;
   
    cout << pete << endl;
    cout << wendy << endl;
    // cout << static_cast<Being&&>(bella) << endl;  // Copy constructor not called (rval ref => no copy)
    cout << static_cast<Being&>(bella) << endl;      // Copy constructor not called (ref => no copy)
    //cout << static_cast<Being>(bella) << endl;     // Copy constructor called
    // cout << bella << endl;                        // Copy constructor not called (no cast => no copy).
    cout << endl;

}
