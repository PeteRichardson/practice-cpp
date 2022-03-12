#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "dbg.h"
#include "log.h"
#include "person.h"

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    setup_console_logging(plog::debug);

    PLOGD << "gday mate!";

    auto filename = "/Users/pete/projects/cpp/streaming/people.txt";
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        PLOGE << "Error while opening file " << filename;
        std::exit(EXIT_FAILURE);
    }

    auto p = std::make_unique<Person>();
    while (ifs >> p->name_ >> p->age_ >> p->gender_) {
        cout << static_cast<std::string>(*p) << '\n';
    }
    cout << std::flush;

    if (ifs.bad()) {
        LOGE << "Exception opening/reading/closing file\n";
        std::exit(EXIT_FAILURE);
    }
    PLOGD << "jiminy christmas!";
    std::exit(EXIT_SUCCESS);
 }
