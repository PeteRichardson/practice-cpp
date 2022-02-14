#include <iostream>

using namespace std;

void my_str_function(string str) {
    cout << str << endl;
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++)
        my_str_function(argv[i]);
}