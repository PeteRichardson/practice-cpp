#include "Node.hxx"

Node::Node(int data) : Node{data, nullptr} {}

Node::Node(int data, Node_up next) : data {data}, next {std::move(next)} {}

std::ostream& operator<<(std::ostream& out, Node& n) {
    return out << n.data;
}
