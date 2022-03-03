#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

class Person {
public:
    string name_{};
    unsigned int age_{};
    char gender_{};

    Person(string name, unsigned int age, char gender);
    Person(const Person& p);    // Copy constructor
    Person& operator=(const Person&);  // Assignment

    // Person(const Person&&);
    // Person& operator=(const Person&); // Copy Assignment?

    ~Person();
};
std::ostream& operator<<(std::ostream&, Person&);

#endif