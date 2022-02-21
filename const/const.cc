#include <iostream>
#include <string>

#include "bank_account.h"

using std::cout, std::endl, std::string;

int main(int argc, char** argv) {

    BankAccount checking { BankAccount(1, 100.00, "Pete")};

    cout << "Welcome to my bank!" << endl;
    cout << "# Dump: " << checking << endl;
    checking.setBalance(250.00);
    cout << "# Dump: " << checking << endl;
    checking.deposit(100.0);
    cout << "# Dump: " << checking << endl;
    checking.deposit(-50.0);
    cout << "# Dump: " << checking << endl;
    checking.withdraw(300.0);
    checking.withdraw(75.0);
    cout << "Have a nice day." << endl;
}