#include "LinkedList.hxx"

LinkedList::LinkedList() : head {nullptr} {}
LinkedList::LinkedList(Node_up n) : head { std::move(n) } {}

LinkedList::LinkedList(int data) {
    auto newNode = std::make_unique<Node>(Node(data));
    if (this->head) {
        newNode->next = std::move(this->head->next);
    }
    this->head = std::move(newNode);
}

LinkedList::LinkedList(std::vector<int> datavec) {
    for (auto data : datavec) {
        this->add(data);
    }
}

auto LinkedList::isEmpty() -> bool {
    return (this->head == nullptr);
}

void LinkedList::add(int data) {
    this->head = std::make_unique<Node>(Node(data, std::move(this->head)));
}

void LinkedList::remove(int data) {
    // Handle empty list
    if (this->isEmpty())
        return;

    // Handle first node matches
    Node* n = this->head.get();
    if (n->data == data) {
        this->head = std::move(this->head->next);
        return;
    }

    // Handle first node does NOT match
    // Walk the list until the end or we find one
    while (n->next && (n->next->data != data))
        n = n->next.get();
    if (n->next)
        n->next = std::move(n->next->next);
}


std::ostream& operator<<(std::ostream& out, LinkedList& ll) {
    if (ll.isEmpty())
        out << "Empty";
    else {
        Node* n = ll.head.get();
        out << *n;
        while (n->next) {
            out << " -> " << n->next->data;
            n = n->next.get();
        }
    }
    return out;
}
