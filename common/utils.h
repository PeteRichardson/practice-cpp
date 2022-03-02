// utils.h

#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <iomanip>
#include <iostream>

void log(std::string);


template <class DT = std::chrono::milliseconds,
          class ClockT = std::chrono::steady_clock>
class Timer
{
    using timep_t = typename ClockT::time_point;
    timep_t _start = ClockT::now(), _end = {};

public:
    void tick() { 
        _end = timep_t{}; 
        _start = ClockT::now(); 
    }
    
    void tock() { _end = ClockT::now(); }
    
    template <class T = DT> 
    auto duration() const { 
        // gsl_Expects(_end != timep_t{} && "tock before reporting"); 
        if (_end == timep_t{})
            throw("tock before reporting"); 
        return std::chrono::duration_cast<T>(_end - _start); 
    }
};


std::ostream& hex64(std::ostream& o);


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
            out << std::hex << std::setw(2) << std::uppercase << std::noshowbase << byte_ptr + i;
        }
    };
    out << std::endl;
    out.flags( f );
    // TODO: make it a real inline stream modifier (i.e. return ostream&...)
    //      i.e.  cout << dump(btp) << endl;
}

#endif