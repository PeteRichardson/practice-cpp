#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

class BankAccount {
public:
    unsigned int account_number_;
    std::string owner_name_;

    BankAccount(unsigned int account_number, double initial_balance, std::string owner_name);
    double getBalance() const;
    double setBalance(double new_balance);
    // double deposit(double amount);
    // double withdraw(double amount);

private:
    double balance_ { 0.00 };
};

std::ostream& operator<< (std::ostream &out, BankAccount const& account);

#endif