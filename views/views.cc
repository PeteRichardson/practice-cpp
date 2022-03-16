// Example of std::ranges::filter_view 
// Not supported (yet 3/16/22) in Clang, so this will only build on gcc

#include <iostream>
#include <vector>
#include <ranges>
#include <memory>

#include <common/person.h>

using std::cout;
using std::ranges::views::filter, std::ranges::views::transform;

using pp = std::shared_ptr<Person>;

auto GetPeopleVector() {
    std::vector<pp> people = { 
        std::make_shared<Person>("Pete",      56, 'M'),
        std::make_shared<Person>("Wendy",     55, 'F'),
        std::make_shared<Person>("Katherine", 17, 'F'),
        std::make_shared<Person>("Bella",      8, 'F'),
    };
    return people;
}

int main(int argc, char** argv) {

    auto isOld = [] (pp person) { return person->age_ > 20; };
    auto justName  = [] (pp person) { return person->name_; };

    auto people = GetPeopleVector();
    auto old_people_names =  people | filter(isOld) | transform(justName); // <----- Cool!

    cout << "A list of old people:\n";
    cout << "---------------------\n";
    for (const auto & name: old_people_names) {
        cout << name  << "\n";
    }
}
