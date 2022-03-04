#include <iostream>
#include <string>

#include "log.h"
#include "person.h"
#include "dbg.h"

using std::cout, std::endl;

int main(int argc, char** argv) {
    // setup_console_logging(plog::none);
    setup_console_logging(plog::debug);

    PLOGD << "Hello, World!";

    auto pete = Person("Pete");
    PLOGW << "pete:\n" << dbg::memdump(pete);


    cout << "This is a test of the emergency broadcasting sytem!" << endl;
    PLOGD << "Goodbye, World!";
}
