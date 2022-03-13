#include <iostream>
#include <future>
#include <chrono>
#include <random>

#include "log.h"
#include "perf.h"

using std::cout, std::endl;

int DoSomething(char c) {
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10,1000);

    for (int i=0; i<10; ++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
        std::cout.put(c).flush();
    }
    return c;
}

int func1() {
    return DoSomething('-');
}

int func2() {
    return DoSomething('.');
}

int main(int argc, char** argv) {
    Timer clock{};
    setup_console_logging(plog::debug);
    PLOGD << "Starting async";
    PLOGD << "func1() in background, func2() in foreground";

    std::future<int> result1(std::async(func1));
    int result2 = func2();

    int result = result1.get() + result2;

    cout << "\nResult of func1('-') + func2('.') = " << result << endl;
    
    clock.tock();
    PLOGD << "Ending async.  Runtime " << clock.duration().count() << "ms";
}
