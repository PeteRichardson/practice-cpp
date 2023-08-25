#include <fmt/core.h>
#include <unistd.h>
#include <vector>

int main(int argc, char** argv) {
    std::vector<int> v{-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto pos=v.begin(); pos < v.end(); ++pos)
        fmt::print("{} ", *pos);
    fmt::print("\n");

    exit(EXIT_SUCCESS);
}