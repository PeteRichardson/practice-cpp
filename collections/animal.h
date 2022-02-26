#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

#include "being.h"

class Animal : public Being {
public:
    std::string breed_;

    Animal(std::string, unsigned int, char, unsigned int, std::string, std::string);
    Animal(const Animal&);
    ~Animal();
    std::ostream& print(std::ostream&) const override;
    std::ostream& dump_fields(std::ostream&) const override;
};

#endif