#include <fmt/core.h>

int main(int argc, char** argv) {

    auto plus10 = [](int i) {
        return i+10;
    };

    fmt::print("7 + 10 is {} inches of fish!\n", plus10(7));
}