#include <iostream>
#include <string>
#include <set>
#include <string_view>

template <typename T>
constexpr auto get_type_name() -> std::string_view
{
#if defined(__clang__)
    constexpr auto prefix = std::string_view{"[T = "};
    constexpr auto suffix = "]";
    constexpr auto function = std::string_view{__PRETTY_FUNCTION__};
#elif defined(__GNUC__)
    constexpr auto prefix = std::string_view{"with T = "};
    constexpr auto suffix = "; ";
    constexpr auto function = std::string_view{__PRETTY_FUNCTION__};
#elif defined(__MSC_VER)
    constexpr auto prefix = std::string_view{"get_type_name<"};
    constexpr auto suffix = ">(void)";
    constexpr auto function = std::string_view{__FUNCSIG__};
#else
# error Unsupported compiler
#endif

    const auto start = function.find(prefix) + prefix.size();
    const auto end = function.find(suffix);
    const auto size = end - start;

    return function.substr(start, size);
}

using std::cout, std::endl, std::string;

using StringSet = std::set<std::string>;

class Being {
public:
    string name_ {};
    unsigned int age_ {};
    char gender_ {};
    unsigned int leg_count_ {};

    Being(string name, unsigned int age, char gender, unsigned int leg_count=0) :
        name_{name}, age_{age}, gender_{gender}, leg_count_{leg_count} {
        cout << "# Created Being(" << name_ << ", " << age_ << ", " << gender_ <<")" << endl;
    }
};

class Human : public Being {
public: 
    string phone_number_;

    Human(string name, unsigned int age, char gender, unsigned int leg_count=2, string phone_number="") :
        Being(name, age, gender, leg_count), phone_number_{phone_number} {
        cout << "# Created Human(" << name_ << ", " << age_ << ", " << gender_ << ", " << phone_number_ << ")" << endl;
    }
};


class Animal : public Being {
public:
    string breed_;

    Animal(string name, unsigned int age, char gender, unsigned int leg_count=4, string breed="") :
        Being(name, age, gender, 4), breed_{breed} {
        cout << "# Created Animal(" << name_ << ", " << age_ << ", " << gender_ << ", " << breed << ")" << endl;
    }
};


std::ostream& operator<<(std::ostream& os, const Being& b) {
    os << b.name_ << ", " << b.age_ << ", " << b.gender_ <<", "<< b.leg_count_ ;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Human& h) {
    os << static_cast<Being>(h) << ", " << h.phone_number_;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Animal& a) {
    os << static_cast<Being>(a) << ", " << a.breed_;
    return os;
}

void dump(auto object) {
    cout << get_type_name<decltype(object)>() << "(" << object << ")" << endl;
}

int main(int argc, char** argv) {
    Being pete{"Pete Richardson", 56, 'M', 2};
    Human wendy{"Wendy Wilson", 55, 'F', 2, "650-218-7915"};
    Animal bella{"Bella", 8, 'F', 4, "Russian Blue"};
    cout << endl;
    // cout << get_type_name<decltype(pete)>() << "(" << pete << ")" << endl;
    // cout << get_type_name<decltype(wendy)>() << "(" << wendy << ")" <<endl;
    // cout << get_type_name<decltype(bella)>() << "(" << bella << ")" <<endl;
    // cout << endl;
    cout << pete << endl;
    cout << wendy << endl;
    cout << bella << endl;
    cout << endl;
    dump(pete);
    dump(wendy);
    dump(bella);

 
    // StringSet people { "Pete", "Wendy", "Katherine"};
    // StringSet pets { "Bella", "Newton", "Zoe"};

    // StringSet family {};
    // family.merge(people);
    // family.merge(pets);

    // for (auto &s: family) {
    //     cout << s << endl;
    // }

    // cout << family.size() << endl;

    // cout << "Bella in the set? " << family.contains("Bella") << endl;

}
