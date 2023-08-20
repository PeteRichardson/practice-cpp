#include <ostream>
#include <memory>

struct Node;
using Node_up = std::unique_ptr<Node>;

typedef struct Node {
    int data;
    Node_up next;

    Node(int);
    Node(int, Node_up);

    friend std::ostream& operator<<(std::ostream&, Node&);
} Node;

