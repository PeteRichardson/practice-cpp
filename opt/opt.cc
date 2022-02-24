#include <iostream>
#include <string>
#include <array>

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    std::array<long long,3> arr {};
    for (int i=0; i<=5; i++) {  // overwrite end of array!  (5 > 3)
        arr[i] = i + 16LL;
    }

    for (int j=0; j<arr.size(); j++) {
        cout << arr[j] << " " << std::flush;
    }
    cout << endl;
}
