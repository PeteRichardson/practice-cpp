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

    Person(string name, unsigned int age, char gender, string ssNumber={});
    Person(string name);
    Person() {};

    Person(const Person& p);    // Copy constructor
    Person& operator=(const Person&);  // Assignment

    // Person(const Person&&);
    // Person& operator=(const Person&); // Copy Assignment?

    ~Person();

    operator string() const;

    string GetSSNumber();
    static string ClassName();

private:
    string ssNumber_ {};
};
std::ostream& operator<<(std::ostream&, Person&);
Person operator"" _person(const char*, size_t);

#endif