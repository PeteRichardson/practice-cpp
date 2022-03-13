#include <iostream>
#include <string>

#include "bank_account.h"
#include <common/log.h>

int main(int argc, char** argv) {
    setup_console_logging(plog::debug);

    PLOGN << "Welcome to my bank!";
    BankAccount checking { BankAccount(1, 100.00, "Pete")};
    PLOGI << "# Dump: " << checking ;
    checking.setBalance(250.00);
    PLOGI << "# Dump: " << checking;
    checking.deposit(100.0);
    PLOGI << "# Dump: " << checking;
    checking.deposit(-50.0);
    PLOGI << "# Dump: " << checking;
    checking.withdraw(300.0);
    checking.withdraw(75.0);
    PLOGN << "Have a nice day.";
}