#include <iostream>
#include <cpp-terminal/base.hpp>

#include <common/log.h>

int main(int argc, char** argv) {
    setup_console_logging(plog::debug);
    PLOGN << Term::color(Term::fg::yellow) << "Hello, World!";
    PLOGD << "This shouldn't be yellow (if plot or cpp-terminal reset the terminal colors automatically)";
}
