#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    cout << "Hello, World!" << endl;

    end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed_time( end - start );
    const double seconds( elapsed_time.count() );
    cout << "# Runtime: " << seconds << "s" << endl;
}