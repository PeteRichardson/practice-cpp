#include <iostream>
#include <span>

using std::cout, std::endl;

int main(int argc, char* argv[]) {

	if (argc == 1) {
		cout << "# usage: " << argv[0] << " <word>..." << endl;
		return(EXIT_FAILURE);
	}

    // put args into a std::span<char*>.   Not really necessary.
	auto args = std::span<char*>{++argv, static_cast<size_t>(--argc)};
    for (auto arg : args) {
		cout << arg << " is " << static_cast<std::string_view>(arg).length() << " chars long." << endl;
	}
    cout << "argv[0] = " << argv[0] << endl;
    cout << "args[1] = " << args[1] << endl;
	return(EXIT_SUCCESS);
}