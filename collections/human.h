#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>

#include "being.h"

class Human : public Being {
public: 
    std::string phone_number_;

    Human(std::string, unsigned int, char, unsigned int, std::string, std::string);
    Human(const Human&);
    ~Human();
    std::ostream& print(std::ostream&) const override;
    std::ostream& dump_fields(std::ostream&) const override;
};

#endif