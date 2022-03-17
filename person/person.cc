#include <iostream>
#include <string>
#include <memory>
#include <array>

#include <common/log.h>
#include <common/dbg.h>
#include <common/person.h>

using std::cout, std::endl, std::string;


int main(int argc, char** argv) {
    setup_console_logging(plog::debug);

    auto pete  = std::make_unique<Person>("Pete", 56, 'M');
    auto wendy = std::make_unique<Person>("Wendy", 55, 'F');
    auto katherine = std::make_unique<Person>("Katherine", 18, 'F');
    auto bella = std::make_unique<Person>("Bella Hand o'the Queen", 8, 'F');
    Person *george_p = new Person("George", 12, 'M');
    Person joe = Person("Joe", 25,'M');

    PLOGD << "*bella: (size " << sizeof *bella << ")\n" << memdump(*bella);
    
    PLOGD << ">>>>>>>>>>>";
    auto george2 = george_p;
    auto george_sp = std::shared_ptr<Person>(george_p);
    auto george3 = george_sp;
    joe = *george_p;
    PLOGD << "<<<<<<<<<<<";

    std::array<std::unique_ptr<Person>, 4> people{};
    try {
        people.at(0) = std::move(pete);
        people.at(1) = std::move(wendy);
        people.at(2) = std::move(katherine);
        people.at(3) = std::move(bella);
        people.at(4) = std::make_unique<Person>(*george_p);  //Should throw here...
    } catch (const std::out_of_range& e) {
        PLOGW << "# CATCH: I guess we're done! " << e.what();
    }
    for (const auto &p: people) {
        cout << *p << '\n';
    }
    cout.flush();
}
