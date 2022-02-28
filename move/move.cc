#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>

using std::cout, std::endl, std::string;

class BigThing {
public:
    unsigned long long number_{};
    unsigned short pos_[4] {};

    BigThing(unsigned long long number, unsigned short x, unsigned short y, unsigned short z, unsigned short a) :
        number_{number}, pos_{x,y,z,a} {
            cout << "# Created BigThing " << number_ << endl;
        }
};

std::ostream& operator<<(std::ostream& out, BigThing bt) {
    out << bt.number_ << ": (" << bt.pos_[0] << "," << bt.pos_[1] << "," << bt.pos_[2] << "," << bt.pos_[3] << ")";
    return out;
};

std::ostream& hex64(std::ostream& o) {
    return o << std::setfill('.') << std::setw(16) << std::hex << std::uppercase << std::noshowbase;
}

void dump_mem(std::ostream& o, const void* obj, const size_t size) {
    auto ptr = (uint64_t*) obj;
    for (auto i = 0; i < size / 8; i++){
        o << hex64 << ptr+i << ": " << hex64 << *(ptr+i) << '\n';
    }
    // TODO: print out last "size % 8" bytes
    // TODO: make it a real inline stream modifier (i.e. return ostream&...)
    //      i.e.  cout << dump(btp) << endl;
    // TODO: make it a template func so we pass in an object ref, not a ptr and size)
}

int main(int argc, char** argv) {
    auto btp = std::make_shared<BigThing>(167ULL, 10,11,12,13);
    cout << *btp << endl;
    cout << "--------------------\n";

    dump_mem(cout, btp.get(), sizeof(*btp));
    cout << std::flush;
}
