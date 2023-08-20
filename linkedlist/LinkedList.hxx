// LinkedList.hxx
#include <vector>
#include <ostream>
#include "Node.hxx"
#include <memory>

class LinkedList {
public:
    Node_up head;

public:
    LinkedList();
    LinkedList(int);
    LinkedList(std::vector<int>);
    LinkedList(Node_up);
    void add(int);
    void remove(int data);
    auto isEmpty() -> bool;
    friend std::ostream& operator<<(std::ostream& out, LinkedList& ll);
};


