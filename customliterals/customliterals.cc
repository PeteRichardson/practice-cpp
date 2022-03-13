#include <iostream>
#include <string>

#include <common/log.h>
#include <common/dbg.h>
#include <common/person.h>

using std::cout, std::endl, std::string;

void DoPerson(Person& p, string message = "") {
    PLOGI << "Dumping " << message;
    PLOGV << "&p\n" << memdump(&p);
    PLOGV << "p\n" << memdump(p);   
    cout << p << endl;
}

void DoPerson(Person&& p, string message = "") {
    PLOGD << "Calling through DoPerson(Person&&, string)";
    DoPerson(p, message);
}

int main(int argc, char** argv) {
    setup_console_logging(plog::verbose);

    PLOGD << "BEGIN";

    DoPerson(Person("Pete", 56, 'M'), R"|(Person pete {"Pete", 56, 'M'})|");
    DoPerson(Person("Wendy"), R"(Person("Wendy"))");
    DoPerson("Wendy"_person, R"("Wendy"_person)");
    DoPerson("Ian"_person, R"("Ian"_person)");

    PLOGD << "END";
}
