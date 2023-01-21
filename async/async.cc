#include <array>
#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <random>

std::mutex coutMutex{};

#include <common/log.h>
#include <common/perf.h>
#include <common/dbg.h>

using std::cout, std::endl, std::async;

int DoSomething(int n) {
    std::random_device rd{};

    for (int i=0; i<10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rd() % 1000));
        std::lock_guard<std::mutex> coutLock(coutMutex);
        auto & out = std::cout;
        out << std::hex << std::noshowbase << std::setw(2) << n << std::endl;
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

    cout << "Reducing results" << endl;

    int result{};
    for (auto i=0; i < n; ++i) {
        result += results[i].get();
    }

    cout << "Done reducing, I guess?" << endl;

    cout << std::dec << std::setw(3) << "\nSum of return values from " << n << " background threads = " << result << endl;
    
    clock.tock();
    PLOGD << "Ending async.  Runtime " << clock.duration().count() << "ms";
}
