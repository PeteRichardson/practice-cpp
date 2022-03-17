#include <array>
#include <iostream>
#include <span>
#include <vector>
#include <string>
#include <string_view>

using std::cout, std::endl, std::string, std::vector;
using strvec = std::vector<std::string_view>;

void dump(std::span<std::string_view> list) {
    for (auto item: list) {
		cout << item << " is " <<  item.length() << " chars long." << endl;
    }
}

int main(int argc, char* argv[]) {

	if (argc == 1) {
		cout << "# usage: " << argv[0] << " <word>..." << endl;
		return(EXIT_FAILURE);
	}

    // args
    auto args = strvec(argv+1, argv+argc);
    dump(args);

    // misc cstrings
    strvec names{"pete", "wendy", "katherine", "bella"};
    dump (names);

    auto pets = std::array<std::string_view, 5>{"Bella", "Newton", "Zoe", "Hannibal", "Ducky"};
    pets[3] = *std::move(std::make_unique<std::string_view>("Axlatl"));
    dump (pets);

    cout << std::hex << &pets[3] << std::dec << endl;

	return(EXIT_SUCCESS);
}