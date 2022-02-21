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

double BankAccount::deposit(double amount) {   
    if (amount < 0.0) {
        cout << "# Error: deposit must be a positive number.  You deposited " << amount << ".   Transaction skipped." << endl;
    } else {
        balance_ += amount;
        cout << "# Deposited $" << amount << " into account #" << account_number_ << ".  New balance = $" << balance_ << "." << endl;
    }
    return balance_;
}

double BankAccount::withdraw(double amount) {   
    if (amount < 0.0) {
        cout << "# Error: withdrawal amount must be a positive number.  You requested " << amount << ".   Transaction skipped." << endl;
        return balance_;
    }
    if (amount > balance_) {
        cout << "# Error: Insufficient funds. You requested $" << amount << ", but there is only $" << balance_ << " in your account.  Transaction skipped." << endl;
        return balance_;
    }
    balance_ -= amount;
    cout << "# Withdrew $" << amount << " from account #" << account_number_ << ".  New balance = $" << balance_ << "." << endl;

    return balance_;
}

std::ostream& operator<< (std::ostream &out, BankAccount const& account) {
    out << account.owner_name_ << "'s account has a balance of $" << account.getBalance() << "."; 
    return out;
}
