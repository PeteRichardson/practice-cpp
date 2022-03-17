#include <array>
#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <random>

#if defined(__unix__) 
#include <syncstream>
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
std::mutex coutMutex{};
#endif

#include <common/log.h>
#include <common/perf.h>
#include <common/dbg.h>

using std::cout, std::endl, std::async;

int DoSomething(int n) {
    std::random_device rd{};

    for (int i=0; i<10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rd() % 1000));

        // On linux we can use c++20 std::osyncstream to wrap cout and make sure the output is 
        // not interleaved.   On Mac (for now), <syncstream> isn't available, so use a mutex
        // and lock_guard.
        // TODO:  What about Windows?
#if defined(__unix__) 
        std::osyncstream(std::cout) << std::hex << std::noshowbase << std::setw(2) << n << std::endl;
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
        std::lock_guard<std::mutex> coutLock(coutMutex);
        std::cout << std::hex << std::noshowbase << std::setw(2) << n << std::endl;
#endif
    }
    return n;
}

int main(int argc, char** argv) {
    Timer clock{};
    setup_console_logging(plog::debug);

    const int n = 50;
    PLOGD << "Starting async on " << n << " background threads.";

    std::array<std::future<int>, n> results{};
    for (auto i=0; i < n; ++i) {
        results[i] = async([=] () { return DoSomething(i); } );
    }

    int result{};
    for (auto i=0; i < n; ++i) {
        result += results[i].get();
    }

    cout << std::dec << std::setw(3) << "\nSum of return values from " << n << " background threads = " << result << endl;
    
    clock.tock();
    PLOGD << "Ending async.  Runtime " << clock.duration().count() << "ms";
}
