#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

void my_str_function(string str) {
    cout << str << " uses my_str_function(string)" << endl;
}

void my_str_function(void *p) { 
    // cout << p << " uses my_str_function(void *p)" << endl;                                       // <-- fails. no implicit conversion from void* to string
    //cout << static_cast<string>(p) << " uses my_str_function(void *p)" << endl;                   // <--- fails. no explicit conversion either
    cout << static_cast<string>(static_cast<char*>(p)) << " uses my_str_function(void *p)" << endl; // <-- works!
    // cout << static_cast<char*>(p) << " uses my_str_function(void *p)" << endl;                   // <-- also works!
}

void my_str_function(char* p) {
    cout << static_cast<string>(p) << " uses my_str_function(char* p)" << endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "# usage: " << argv[0] << "<string>" << endl;
        return 1;
    }

    // Test 1:  just a string literal.  which func will it match?
    // NOTE:  gcc spits out: "warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]"
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wwrite-strings"
    my_str_function("Test 1: string literal!");
    #pragma GCC diagnostic pop

    // Test 2:  basically the same thing... just for completeness
    auto s = "Test 2: auto var";
    my_str_function(s);

    // Test 3:  explicit char ptr to character array
    char chararray[30] = "Test 3: char ptr to chararray";
    char* t = &chararray[0];
    my_str_function(t);

    // Test 4:  explicit void ptr to character array
    char anotherchararray[30] = "Test 4: void ptr to chararray";
    void* q = &anotherchararray[0];
    my_str_function(q);

    // Test 5:  something from the cmd line
    my_str_function(argv[1]);
    // Test 6:  command line arg, but cast to string (no surprise here).
    my_str_function(static_cast<string>(argv[1]));

}