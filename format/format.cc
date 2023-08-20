#include <iostream>
#include <fmt/core.h>

int main(int argc, char** argv) {

    auto fish_length = 8.79231; // in inches
    auto fish_count = 672;
    auto all_fish_length = fish_length * fish_count;   // inches

    fmt::print("I have {:.2f} inches of fish!\n", all_fish_length);
}