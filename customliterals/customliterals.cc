#include <iostream>
#include <string>

#include "log.h"
#include "dbg.h"
#include "person.h"

using std::cout, std::endl, std::string;

void DoPerson(Person& p, string message = "") {
    PLOGI << "Creating " << message;
    PLOGD << "&p\n" << dbg::memdump(&p);
    PLOGD << "p\n" << dbg::memdump(p);   
    cout << p << endl;

}

void DoPerson(Person&& p, string message = "") {
    PLOGV << "Calling through DoPerson(Person&&, string)";
    DoPerson(p, message);
}

int main(int argc, char** argv) {
    setup_console_logging(plog::warning);

    PLOGV << "BEGIN";

    DoPerson(Person("Pete", 56, 'M'), R"|(Person pete {"Pete", 56, 'M'}")|");
    DoPerson(Person("Wendy"), R"|(Person("Wendy"))|");
   
    auto wendy = "Wendy"_person;
    DoPerson(wendy, R"|("Wendy"_person)|");
    
    auto ian = "Ian"_person;
    DoPerson(ian, R"("Ian"_person)");
    PLOGV << "END";
}
