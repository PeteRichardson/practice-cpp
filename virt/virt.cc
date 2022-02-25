// taken from
//      https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

class Base {
public:
    virtual void print() const {
        cout << "Base!" << endl;
    }
};

class Derived : public Base {
public:
    void print() const override {
        cout << "Derived!" << endl;
    }
};


int main(int argc, char** argv) {
    Derived d{};
    Base& b{ d };

    d.print();
    b.print();
    return 0;
}
