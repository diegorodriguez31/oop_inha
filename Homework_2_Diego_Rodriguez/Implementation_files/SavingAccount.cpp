#include "../Header_files/SavingAccount.h"

// Here, we define the constructor of the SavingAccount class based on Account class and we add the rate parameter
SavingAccount::SavingAccount(int ID, int balance, char* cname, int rate)
: Account(ID, balance, cname), m_InterestRate{rate} {};

void SavingAccount::Deposit(int money) {
    // First, we call the deposit function of the base class
    Account::Deposit(money);
    // Then, we add the interest rate to the balance by doing another deposit
    Account::Deposit(money * (m_InterestRate / 100.0));
}