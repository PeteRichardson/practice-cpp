#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

class BankAccount {
public:
    unsigned int account_number_;
    string owner_name_;

    BankAccount(unsigned int account_number, double initial_balance, string owner_name);
    double getBalance() const;
    double setBalance(double new_balance);
    // double deposit(double amount);
    // double withdraw(double amount);

private:
    double balance_ { 0.00 };
};

BankAccount::BankAccount(unsigned int account_number, double initial_balance, string owner_name) :
    account_number_{account_number}, balance_{initial_balance}, owner_name_{owner_name} {
        cout << "# Created account #" << account_number_ << " with initial balance $" << balance_ << " for " << owner_name_ <<"." << endl;
}

double BankAccount::getBalance() const {
    return balance_;
}

double BankAccount::setBalance(double new_balance) {
    cout << "# Warning: overriding balance for account #" << account_number_ << ".  Old balance: " << balance_ << ".  New balance: " << new_balance << "." << endl;
    balance_ = new_balance;
    return balance_;
}

std::ostream& operator<< (std::ostream &out, BankAccount const& account) {
    out << account.owner_name_ << "'s account has a balance of $" << account.getBalance() << "."; 
    return out;
}


int main(int argc, char** argv) {

    BankAccount checking { BankAccount(1, 100.00, "Pete")};

    cout << "Welcome to my bank!" << endl;
    cout << "# Dump: " << checking << endl;
    checking.setBalance(250.00);
    cout << "# Dump: " << checking << endl;
    cout << "Have a nice day." << endl;
}