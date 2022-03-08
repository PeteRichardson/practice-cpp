// taken from
//      https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

class Base {
public:
    friend std::ostream& operator<<(std::ostream&out, const Base& b) {
        return b.print(out);
    }

    virtual std::ostream& print(std::ostream& out) const {
        out << "Base class";
        return out;
    }
};

class Derived : public Base {
public:
    std::ostream& print(std::ostream& out) const override { // no need for 'virtual' here.  implied by override
        out << "Derived class";
        return out;
    }
};

int main(int argc, char** argv) {
    Base    b{};
    Derived d{};
    Base&   bref{ d };

    cout << b << '\n';    //  should print "Base"
    cout << d << '\n';    //  should print "Derived"
    cout << bref << endl; //  should print "Derived"
    return 0;
}
