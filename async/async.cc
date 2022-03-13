#include <iostream>
#include <future>
#include <chrono>
#include <random>
#include <array>

#include <common/log.h>
#include <common/perf.h>
#include <common/dbg.h>

using std::cout, std::endl, std::async;

int DoSomething(char c) {
    std::random_device rd{};

    for (int i=0; i<10; ++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(rd() % 1000));
        std::cout.put(c).flush();
    }
    return c;
}

int main(int argc, char** argv) {
    Timer clock{};
    setup_console_logging(plog::debug);

    const int n = 10;
    PLOGD << "Starting async on " << n << " background threads.";

    std::array<std::future<int>, n> results{};
    for (auto i=0; i < n; ++i) {
        results[i] = async([=] () { return DoSomething(i+0x30); } );  // pass in chars '0'-'9' (i.e. 0x30, 0x31...0x39)
    }

    int result{};
    for (auto i=0; i < n; ++i) {
        result += results[i].get();
    }

    cout << "\nSum of return values from " << n << " background threads = " << result << endl;
    
    clock.tock();
    PLOGD << "Ending async.  Runtime " << clock.duration().count() << "ms";
}
