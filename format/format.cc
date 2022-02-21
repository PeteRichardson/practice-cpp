#include <iostream>

int main(int argc, char** argv) {

    auto fish_length = 8.79231; // in inches
    auto fish_count = 672;
    auto all_fish_length = fish_length * fish_count;   // inches

    std::cout << "I have " << all_fish_length << " inches of fish!" << std::endl;
}