#include "bank_account.h"

#include <iostream>
#include <string>
#include "log.h"

using std::string;

BankAccount::BankAccount(unsigned int account_number, double initial_balance, string owner_name) :
    account_number_{account_number}, balance_{initial_balance}, owner_name_{owner_name} {
        PLOGI << "# Created account #" << account_number_ << " with initial balance $" << balance_ << " for " << owner_name_ <<".";
}

double BankAccount::getBalance() const {
    return balance_;
}

double BankAccount::setBalance(double new_balance) {
    PLOGW << "# Warning: overriding balance for account #" << account_number_ << ".  Old balance: " << balance_ << ".  New balance: " << new_balance << ".";
    balance_ = new_balance;
    return balance_;
}

double BankAccount::deposit(double amount) {   
    if (amount < 0.0) {
        PLOGN << "Error: deposit must be a positive number.  You deposited " << amount << ".   Transaction skipped.";
    } else {
        balance_ += amount;
        PLOGN << "# Deposited $" << amount << " into account #" << account_number_ << ".  New balance = $" << balance_ << ".";
    }
    return balance_;
}

double BankAccount::withdraw(double amount) {   
    if (amount < 0.0) {
        PLOGN << "Error: withdrawal amount must be a positive number.  You requested " << amount << ".   Transaction skipped.";
        return balance_;
    }
    if (amount > balance_) {
        PLOGN << "Error: Insufficient funds. You requested $" << amount << ", but there is only $" << balance_ << " in your account.  Transaction skipped.";
        return balance_;
    }
    balance_ -= amount;
    PLOGI << "# Withdrew $" << amount << " from account #" << account_number_ << ".  New balance = $" << balance_ << ".";

    return balance_;
}

std::ostream& operator<< (std::ostream &out, BankAccount const& account) {
    out << account.owner_name_ << "'s account has a balance of $" << account.getBalance() << "."; 
    return out;
}
