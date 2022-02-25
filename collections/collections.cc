#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

class Being {
public:
    string name_ {};
    unsigned int age_ {};
    char gender_ {};
    unsigned int leg_count_ {};

    Being(string name, unsigned int age, char gender, unsigned int leg_count={}, string ss_number={"000-00-0000"}) :
        name_{name}, age_{age}, gender_{gender}, leg_count_{leg_count}, ss_number_{ss_number} {
        cout << "# Created Being " << name_ << endl;
    }

    // friend std::ostream& operator<<(std::ostream& out, const Being& b) {
    //     return b.print(out);
    // }

    virtual std::ostream& print(std::ostream& out) const {
        out << "Being("; dump_fields(out); out << ")";
        return out;
    }

    virtual std::ostream& dump_fields(std::ostream& out) const {
        out << name_ << ", " << age_ << ", " << gender_ << ", " << leg_count_ << ", " << ss_number_;
        return out;
    }

private:
    string ss_number_ {};
};


std::ostream& operator<<(std::ostream& out, const Being& b) {
    return b.print(out);
}


class Human : public Being {
public: 
    string phone_number_;

    Human(string name, unsigned int age, char gender, unsigned int leg_count=2, string ss_number="000-00-0000", string phone_number="") :
        Being(name, age, gender, leg_count, ss_number), phone_number_{phone_number} {
        cout << "# Created Human: " << name_ << endl;
    }

    std::ostream& print(std::ostream& out) const override {
        out << "Human("; dump_fields(out); out << ")";
        return out;
    }

    std::ostream& dump_fields(std::ostream& out) const override {
        Being::dump_fields(out);
        out << ", " << phone_number_;
        return out;
    }
};


class Animal : public Being {
public:
    string breed_;

    Animal(string name, unsigned int age, char gender, unsigned int leg_count=4, string ss_number="111-11-1111", string breed="") :
        Being(name, age, gender, 4, ss_number), breed_{breed} {
        cout << "# Created Animal " << name_ << endl;
    }

    std::ostream& print(std::ostream& out) const override {
        out << "Animal("; dump_fields(out); out << ")";
        return out;
    }

    std::ostream& dump_fields(std::ostream& out) const override {
        Being::dump_fields(out);
        out << ", " << breed_;
        return out;
    }
};

int main(int argc, char** argv) {
    Being pete{"Pete Richardson", 56, 'M', 2, "xxx-xx-1234"};
    Human wendy{"Wendy Wilson", 55, 'F', 2, "xxx-xx-5678", "650-218-7915"};
    Animal bella{"Bella", 8, 'F', 4, "zzz-zzz-4321", "Russian Blue"};
    cout << endl;
   
    cout << pete << endl;
    cout << wendy << endl;
    cout << bella << endl;

}
