#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>

using std::cout, std::endl, std::string;

std::ostream& hex64(std::ostream& o) {
    return o << std::setfill('.') << std::setw(16) << std::hex << std::uppercase << std::noshowbase;
}

template <typename T> 
void dump(std::ostream& out, T& obj) {
    auto ptr = (uint64_t*) &obj;
    size_t size = sizeof(T);
    std::ios_base::fmtflags f( out.flags() );
    out << "type: " << typeid(obj).name() << ", size: " << size;
    out << "\n--------------------\n";
    for (auto i = 0; i < size / 8; i++){
        out << hex64 << ptr+i << ": " << hex64 << *(ptr+i) << '\n';
    }
    auto remainder = size % 8;
    if (remainder > 0) {
        auto byte_ptr = (uint8_t*) (ptr + (size / 8));
        out << hex64 << (uint64_t*) byte_ptr << ": ";
        for (auto i = 0; i < remainder; i++) {
            cout << std::hex << std::setw(2) << std::uppercase << std::noshowbase << byte_ptr + i;
        }
    };
    out << endl;
    cout.flags( f );
    // TODO: make it a real inline stream modifier (i.e. return ostream&...)
    //      i.e.  cout << dump(btp) << endl;
}

#pragma pack(0)
class Person {
public:
    string name_{};
    unsigned int age_{};
    char gender_{};

    Person(string name, unsigned int age, char gender) : name_{name}, age_{age}, gender_{gender} {
        cout << "# Created Person@" << this << "(name: "<< name_ << ")" << endl;
    }

    friend std::ostream& operator<<(std::ostream& out, Person& p) {
        out << "Person(" << p.name_ << "," << p.age_ << "," << p.gender_ << ")";
        return out;
    }
};
#pragma options align=reset

int main(int argc, char** argv) {
    //Person pete{"Pete Richardson", 56, 'M'};
    auto pete = std::make_shared<Person>("Pete Richardson", 56, 'M');
    auto wendy = std::make_shared<Person>("Wendy Wilson", 55, 'F');
    dump(cout, *pete);
    dump(cout, *wendy);
}
