#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using std::string;

class Person {
public:
    string name {};
    unsigned int age {};
    char gender {};

    Person(string name, unsigned int age, char gender, string ssNumber);
    Person() {};
    string GetSSNumber();
    static string ClassName();

private:
    string ssNumber {};
};

#endif
