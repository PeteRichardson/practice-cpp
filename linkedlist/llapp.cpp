#include <iostream>
#include "LinkedList.hxx"

using std::cout, std::endl;

int main(int argc, char** argv) {
    auto ll {LinkedList{3}};
    ll.add(4);
    cout << ll << endl;

    cout << "test remove 1: remove(45) from empty\n\tbefore: ";
    auto llr1 {LinkedList{}};
    cout << llr1 << endl;
    llr1.remove(45);
    cout << "\tafter: " << llr1 << endl;

    cout << "test remove 2: remove(45) from [45]\n\tbefore: ";
    auto llr2 {LinkedList{45}};
    cout << llr2 << endl;
    llr2.remove(45);
    cout << "\tafter: " << llr2 << endl;

    cout << "test remove 3: remove(45) from [27]\n\tbefore: ";
    auto llr3 = LinkedList(27);
    cout << llr3 << endl;
    llr3.remove(45);
    cout << "\tafter: " << llr3 << endl;

    cout << "test remove 4: remove(45) from [27, 45]\n\tbefore: ";
    auto llr4 = LinkedList(std::vector<int>{27, 45});
    cout << llr4 << endl;
    llr4.remove(45);
    cout << "\tafter: " << llr4 << endl;

    cout << "test remove 5: remove(45) from [45, 27]\n\tbefore: ";
    auto llr5 = LinkedList(std::vector<int>{45, 27});
    cout << llr5 << endl;
    llr5.remove(45);
    cout << "\tafter: " << llr5 << endl;

    auto ll2 = LinkedList(std::vector<int> {1,2,3,4,5});
    cout << ll2 << endl;
    cout << "removing 3" << endl;
    ll2.remove(3);
    cout << ll2 << endl;

    auto ll3 = LinkedList();
    ll3.add(4);
    cout << ll3 << endl;

    return EXIT_SUCCESS;
}