#include <iostream>
#include <future>
#include <chrono>
#include <random>

#include "log.h"
#include "perf.h"

using std::cout, std::endl, std::async;

int DoSomething(char c) {
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10,1000);

    for (int i=0; i<10; ++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
        std::cout.put(c).flush();
    }
    return c;
}

int main(int argc, char** argv) {
    Timer clock{};
    setup_console_logging(plog::debug);
    PLOGD << "Starting async";
    PLOGD << "func1() in background, func2() in foreground";

    auto result1( async([] () { return DoSomething('-'); } ) );
    auto result2( async([] () { return DoSomething('.'); } ) );

    int result = result1.get() + result2.get();

    cout << "\nResult of func1('-') + func2('.') = " << result << endl;
    
    clock.tock();
    PLOGD << "Ending async.  Runtime " << clock.duration().count() << "ms";
}
