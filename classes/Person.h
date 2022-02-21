#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using std::string;

class Person {
public:
    string name_ {};
    unsigned int age_ {};
    char gender_ {};

    Person(string name, unsigned int age, char gender, string ssNumber);
    Person(string name);
    Person() {};
    string GetSSNumber();
    static string ClassName();

private:
    string ssNumber_ {};
};

#endif
