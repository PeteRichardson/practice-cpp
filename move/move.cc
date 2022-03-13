#include <iomanip>
#include <iostream>
#include <string>
#include <cstdint>

#include <common/dbg.h>

using std::cout, std::endl;

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
            cout << "# Created BigThing " << number_ << " @" << this << ".  size= "<< sizeof(BigThing) << endl;
        }

    friend std::ostream& operator<<(std::ostream& out, BigThing bt) {
        out << "BigThing " << bt.number_ << ": (" << bt.pos_[0] << "," << bt.pos_[1] << "," << bt.pos_[2] << "," << bt.pos_[3] << ")";
        return out;
    };
};
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wignored-pragmas"
#pragma options align=reset
#pragma clang diagnostic pop

int main(int argc, char** argv) {
    auto btp = std::make_unique<BigThing>(167ULL, 42,43,44);
    cout << *btp << '\n' << memdump(*btp) << endl;
}


