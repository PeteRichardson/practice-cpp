#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <any>

using std::cout, std::endl, std::string;

typedef std::bitset<64> Bits;



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

std::ostream& dump_mem(std::ostream& o, void* obj, size_t size) {
    // cout << size << endl;
    uint64_t* ptr = reinterpret_cast<uint64_t*>(obj);
    return o << hex64 << (uint64_t) ptr << ": " << hex64 << *ptr << " " << hex64 << *(ptr+1) << '\n';
}

int main(int argc, char** argv) {
    auto btp = std::make_shared<BigThing>(167ULL, 10,11,12,13);
    cout << *btp << endl;
    cout << "--------------------\n";

    dump_mem(cout, btp.get(), sizeof(*btp));
    cout << std::flush;
}
