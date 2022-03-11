#ifndef BEING_H
#define BEING_H

#include <iostream>
#include <string>

class Being {
public:
    std::string name_ {};
    unsigned int age_ {};
    char gender_ {};
    unsigned int leg_count_ {};

    Being(std::string, unsigned int, char, unsigned int, std::string);

    // Copy constructor that logs copies
    Being(const Being&);

    virtual ~Being();

    virtual std::ostream& print(std::ostream&) const;

    virtual std::ostream& dump_fields(std::ostream&) const;

private:
    std::string ss_number_ {};
    Being& operator=( const Being& rhs ) = delete;
};

std::ostream& operator<<(std::ostream&, const Being&);

#endif