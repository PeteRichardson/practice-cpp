#include <gtest/gtest.h>

#include "../bank_account.h"

TEST(BankAccountTests, Construction) {
    BankAccount checking { BankAccount(1, 100.00, "Pete")};
    EXPECT_EQ(checking.getBalance(), 100.0);
    EXPECT_STREQ(checking.owner_name_.c_str(), "Pete");
    EXPECT_EQ(checking.account_number_, 1);
}

TEST(BankAccountTests, Deposit) {
    BankAccount checking { BankAccount(1, 100.00, "Pete")};
    checking.deposit(123.75);
    EXPECT_EQ(checking.getBalance(), 223.75);
}

TEST(BankAccountTests, DepositNegative) {
    BankAccount checking { BankAccount(1, 100.00, "Pete")};
    auto balance_before = checking.getBalance();
    checking.deposit(-123.75);

    // A negative deposit is invalid
    // Transaction is ignored and balance should be unchanged.
    EXPECT_EQ(checking.getBalance(), balance_before);
}

TEST(BankAccountTests, Withdraw) {
    BankAccount checking { BankAccount(1, 100.00, "Pete")};
    checking.withdraw(51.00);
    EXPECT_EQ(checking.getBalance(), 49.00);
}

TEST(BankAccountTests, WithdrawNegative) {
    BankAccount checking { BankAccount(1, 100.00, "Pete")};
    auto balance_before = checking.getBalance();
    checking.withdraw(-23.75);

    // A negative withdrawal is invalid.
    // Transaction is ignored and balance should be unchanged.
    EXPECT_EQ(checking.getBalance(), balance_before);
}

TEST(BankAccountTests, Overdraw) {
    BankAccount checking { BankAccount(1, 100.00, "Pete")};
    auto balance_before = checking.getBalance();
    checking.withdraw(-175.00);

    // You can't withdraw more than your balance.
    // Transaction is ignored and balance should be unchanged.
    EXPECT_EQ(checking.getBalance(), balance_before);
}
