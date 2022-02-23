#include <iostream>
#include <string>
#include <deque>

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    std::deque<int> coll {};
    for (int i=24; i<=30; i++) {
        coll.push_front(i);
    }

    for (int j=0; j<coll.size(); j++) {
        cout << coll[j] << " ";
    }
    cout << endl;
}
