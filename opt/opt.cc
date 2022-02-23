#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {
    std::vector<int> coll {};
    for (int i=24; i<=30; i++) {
        coll.push_back(i);
    }

    for (int j=0; j<coll.size(); j++) {
        cout << coll[j] << " ";
    }
    cout << endl;
}
