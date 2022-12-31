#include "../Header_files/HighCreditAccount.h"

// Here, we define the constructor of the HighCreditAccount class based on SavingAccount class and we add the special rate parameter
HighCreditAccount::HighCreditAccount(int ID, int balance, char* cname, int rate, int special)
: SavingAccount(ID, balance, cname, rate), m_SpecialRate{special} {};

void HighCreditAccount::Deposit(int money) {
    // First, we call the deposit function of the SavingAccount class
    SavingAccount::Deposit(money);
    // Then, we add the special rate to the balance by doing another deposit but here with
    // the Account class so that we do not add the interest rate again
    Account::Deposit(money * (m_SpecialRate / 100.0));
}