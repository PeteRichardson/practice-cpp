#ifndef HEXDUMP_H
#define HEXDUMP_H

#include <iomanip>

template <typename T>
void hexdump(std::ostream& out, T& obj, std::string message="") {
    std::size_t size{sizeof obj};
    out << message << " @" << std::hex << std::noshowbase << (unsigned long) &obj << " : " <<std::dec << size << " bytes" << '\n';
    out << "\t..." << endl;
}

std::ostream& hex64(std::ostream& o) {
    return o << std::setfill('.') << std::setw(16) << std::hex << std::uppercase << std::noshowbase;
}

template <typename T> 
void dump(std::ostream& out, T& obj, string message) {
    auto ptr = (uint64_t*) &obj;
    size_t size = sizeof(T);
    std::ios_base::fmtflags f( out.flags() );
    out << message << "... type: " << typeid(obj).name() << ", size: " << size << '\n';
    // out << "\n--------------------\n";
    for (auto i = 0; i < size / 8; i++){
        out << hex64 << ptr+i << ": " << hex64 << *(ptr+i) << '\n';
    }
    auto remainder = size % 8;
    if (remainder > 0) {
        auto byte_ptr = (uint8_t*) (ptr + (size / 8));
        out << hex64 << (uint64_t*) byte_ptr << ": ";
        for (auto i = 0; i < remainder; i++) {
            out << std::hex << std::setw(2) << std::uppercase << std::noshowbase << byte_ptr + i;
        }
    };
    out << std::endl;
    out.flags( f );
    // TODO: make it a real inline stream modifier (i.e. return ostream&...)
    //      i.e.  cout << dump(btp) << endl;
}

#endif