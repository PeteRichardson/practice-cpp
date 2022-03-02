#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>

using std::cout, std::endl, std::string;

#pragma pack(0)
class BigThing {
public:
    unsigned long long number_{};
    char pos_[4] {};
    unsigned int muhshortz {0xAAAAAAAA};
    char c{'a'};
    unsigned long muhlong {0x5555555555555555};
    unsigned long number2_{0x6666666666666666};
    unsigned long dummy {1};

    BigThing(unsigned long long number, char x, char y, char z) :
        number_{number}, pos_{x, y, z, 'G'} {
            cout << "# Created BigThing " << number_ << ".  size= "<< sizeof(BigThing) << endl;
        }
};
#pragma options align=reset

std::ostream& operator<<(std::ostream& out, BigThing bt) {
    out << bt.number_ << ": (" << bt.pos_[0] << "," << bt.pos_[1] << "," << bt.pos_[2] << "," << bt.pos_[3] << ")";
    return out;
};

// class Dumper {
// public:
//     Dumper(BigThing obj) : obj_{obj} {}
//     void operator()(std::ostream& o) const {
//         o << "big foo bottom pants obj size=" << sizeof(obj_);
//     }
// private:
//     BigThing obj_;
// };

// Dumper dump_object(BigThing obj) {
//     return Dumper(obj);
// }


std::ostream& hex64(std::ostream& o) {
    return o << std::setfill('.') << std::setw(16) << std::hex << std::uppercase << std::noshowbase;
}

void dump(std::ostream& o, const void* obj, const size_t size) {
    auto ptr = (uint64_t*) obj;
    for (auto i = 0; i < size / 8; i++){
        o << hex64 << ptr+i << ": " << hex64 << *(ptr+i) << '\n';
    }
    auto remainder = size % 8;
    if (remainder > 0) {
        auto byte_ptr = (uint8_t*) (ptr + (size / 8));
        o << hex64 << (uint64_t*) byte_ptr << ": ";
        for (auto i = 0; i < remainder; i++) {
            cout << std::hex << std::setw(2) << std::uppercase << std::noshowbase << byte_ptr + i;
        }
        cout << endl;
    };
    // TODO: make it a real inline stream modifier (i.e. return ostream&...)
    //      i.e.  cout << dump(btp) << endl;
    // TODO: make it a template func so we pass in an object ref, not a ptr and size)
}

int main(int argc, char** argv) {
    auto btp = std::make_shared<BigThing>(167ULL, 42,43,44);
    cout << *btp << endl;
    cout << "--------------------\n";

    // cout << dump_object(btp));

    dump(cout, btp.get(), sizeof(*btp));
    cout << std::flush;
}


