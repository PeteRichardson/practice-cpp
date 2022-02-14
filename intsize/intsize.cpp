#include <iostream>
#include <ostream>
#include <curses.h>

using namespace std;

int main (int argc, char**argv) {
    short x {32767};

    initscr();
    printw("Hello, World!");
    std::cout << "x = " << x << std::endl;
    getch();
    endwin();
    
}