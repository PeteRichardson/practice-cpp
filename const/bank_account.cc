#include "bank_account.h"

#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

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
