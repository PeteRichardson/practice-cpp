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
    cout << "Have a nice day." << endl;
}