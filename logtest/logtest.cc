#include <iostream>
#include <string>
#include <thread>

#include <common/log.h>
#include <common/person.h>
#include <common/dbg.h>
#include <common/perf.h>

using std::cout, std::endl;

int main(int argc, char** argv) {
    setup_console_logging(plog::debug);

    Timer clock;
    clock.tick();

    PLOGD << "Hello, World!";

    auto pete = Person("Pete");
    PLOGW << "pete:\n" << memdump(pete);

    cout << "This is a test of the emergency broadcasting sytem!" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds{250});

    clock.tock();
    PLOGD << "# Runtime: " << clock.duration().count() << "ms" << endl;
}
