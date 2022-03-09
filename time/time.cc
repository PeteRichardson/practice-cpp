#include <iostream>
#include <string>
#include <thread>

#include "perf.h"

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {

    Timer clock;
    clock.tick();

    cout << "Hello, World!" << endl;
    std::this_thread::sleep_for(std::chrono::seconds{2});

    clock.tock();
    cout << "# Runtime: " << clock.duration().count() << "ms" << endl;
}