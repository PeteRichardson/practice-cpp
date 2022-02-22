// utils.h
#include <iostream>
#include <chrono>

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