#include "../Header_files/AccountHandler.h"

// I initialize the whole account array to nullptr
AccountHandler::AccountHandler(): m_accNum{0} {
    for (int i = 0; i < MAX_ACC_NUM; i++) {
        m_accArr[i] = nullptr;
    }
}

// We only need to delete the accounts that have been created
AccountHandler::~AccountHandler() {
    for (int i = 0; i < m_accNum; i++) {
        delete m_accArr[i];
    }
}

// You can notice in the menu that I added the options number 5,6 and 7 compared to the subject
void AccountHandler::ShowMenu(void) const
{
    cout << endl;
    cout << "-----Menu------------------------" << endl;
    cout << "1. Make account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Display all" << endl;
    cout << "5. Display one" << endl;
    cout << "6. Delete account" << endl;
    cout << "7. Delete all" << endl;
    cout << "8. Exit program" << endl;
    cout << "---------------------------------" << endl;
}

void AccountHandler::MakeAccount(void) {
    int accountType;
    // Check if the number of accounts is not superior to the maximum number of accounts possible
    if (m_accNum >= MAX_ACC_NUM) {
        cout << "Account number is full, cannot make an account anymore" << endl;
        return;
    }

    cout << "[Select Account Type]" << endl;
    cout << "1. Saving Account" << endl;
    cout << "2. High Credit Account" << endl;
    cout << "Select: ";
    cin >> accountType;
    // According to the selected type, we create the SavingAccount or the HighCreditAccount
    switch(accountType){
        case 1:
            MakeSavingAccount();
            break;
        case 2:
            MakeHighCreditAccount();
            break;
        default:
            cout << "Invalid account type" << endl;
            break;
    }
}

void AccountHandler::DepositMoney(void) {
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    if (CinIgnore() == -1) {
        return;
    }
    cout << "Deposit amount: ";
    cin >> money;
    if (CinIgnore() == -1) {
        return;
    }

    int idx = GetAccIdx(id);
    if (idx == -1) {
        cout << "Error: Account ID does not exist" << endl;
        return;
    }

    // We can just call the member function Deposit of the Account class
    m_accArr[idx]->Deposit(money);
    cout << "Deposit complete" << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
    int money;
    int id;
    cout << "[Withdrawal]" << endl;
    cout << "Account ID: ";
    cin >> id;
    if (CinIgnore() == -1) {
        return;
    }
    cout << "Withdrawal amount: ";
    cin >> money;
    if (CinIgnore() == -1) {
        return;
    }

    int idx = GetAccIdx(id);
    if (idx == -1) {
        cout << "Error: Account ID does not exist" << endl;
        return;
    }

    // We can just call the member function Withdraw of the Account class
    if (m_accArr[idx]->Withdraw(money) == -1) {
        cout << "Error: Insufficient balance" << endl;
        return;
    }
    cout << "Withdrawal complete" << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const{
    cout << "[Display all]" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < m_accNum; i++) {
        // We can just call the member function ShowAccInfo of the Account class
        m_accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

void AccountHandler::ShowAccInfo(void) const{
    int id;
    cout << "[Account that you want to display]" << endl;
    cin >> id;
    if (CinIgnore() == -1) {
        return;
    }
    int idx = GetAccIdx(id);
    if (idx == -1) {
        cout << "Error: Account ID does not exist" << endl;
        return;
    }

    // We can just call the member function ShowAccInfo of the Account class
    m_accArr[idx]->ShowAccInfo();
}

// This function is usefull to verify if the id entered by the user is a valid ID or not
int AccountHandler::GetAccIdx(int id) const{
    for (int i = 0; i < m_accNum; i++) {
        if (m_accArr[i]->GetAccID() == id) {
            return i;
        }
    }
    return -1;
}

void AccountHandler::DeleteAccount(void) {
    int id;
    cout << "[Delete account]" << endl;
    cin >> id;
    if (CinIgnore() == -1) {
        return;
    }
    int idx = GetAccIdx(id);
    if (idx == -1) {
        cout << "Error: Account ID does not exist" << endl;
        return;
    }

    cout << "This account is being deleted:" << endl;
    m_accArr[idx]->ShowAccInfo();

    // We just have to call the destructor of the Account class
    m_accArr[idx]->~Account();
    for (int i = idx; i < m_accNum - 1; i++) {
        m_accArr[i] = m_accArr[i + 1];
    }
    m_accNum--;
    cout << "Delete complete" << endl << endl;
}

void AccountHandler::DeleteAllAccounts(void) {
    cout << "All accounts are being deleted" << endl << endl;
    for (int i = 0; i < m_accNum; i++) {
        cout << "Account deleted" << endl;
        cout << "---------------------------------" << endl;
        m_accArr[i]->ShowAccInfo();
        // We just have to call the destructor of the Account class
        m_accArr[i]->~Account();
    }
    m_accNum = 0;
    cout << "Delete complete" << endl << endl;
}

// The idea of this method is the same as the original creation of account but we add
// the interest rate parameter so the user need to enter it
void AccountHandler::MakeSavingAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;
    int interestRate;

    cout << "[Make Saving Account]" << endl;
    cout << "Account ID: ";
    cin >> id;
    if (CinIgnore() == -1) {
        return;
    }
    cout << "Customer name: ";
    cin >> name;
    if (CinIgnore() == -1) {
        return;
    }
    cout << "Deposit amount: ";
    cin >> balance;
    if (CinIgnore() == -1) {
        return;
    }

    cout << "Interest Rate: ";
    cin >> interestRate;
    if (CinIgnore() == -1) {
        return;
    }

    cout << endl;

    if (GetAccIdx(id) != -1){
        cout << "Error: Account ID already exists" << endl;
        return;
    }

    // We add to the array this new SavingAccount composed of all the user input
    m_accArr[m_accNum] = new SavingAccount(id, balance, name, interestRate);
    m_accNum++;
}

// The idea of this method is the same as the original creation of account but we add
// the interest rate parameter and special rate parameter so the user need to enter it
void AccountHandler::MakeHighCreditAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;
    int interestRate;
    int classRate;
    int specialRate;

    cout << "[Make High Credit Account]" << endl;
    cout << "Account ID: ";
    cin >> id;
    if (CinIgnore() == -1) {
        return;
    }
    cout << "Customer name: ";
    cin >> name;
    if (CinIgnore() == -1) {
        return;
    }
    cout << "Deposit amount: ";
    cin >> balance;
    if (CinIgnore() == -1) {
        return;
    }

    cout << "Interest Rate: ";
    cin >> interestRate;
    if (CinIgnore() == -1) {
        return;
    }

    cout << "Credit Rating(A:1, B:2, C:3): ";
    cin >> classRate;
    if (CinIgnore() == -1) {
        return;
    }

    cout << endl;

    if (GetAccIdx(id) != -1){
        cout << "Error: Account ID already exists" << endl;
        return;
    }

    switch (classRate) {
        case 1:
            specialRate = 7;
            break;
        case 2:
            specialRate = 4;
            break;
        case 3:
            specialRate = 2;
            break;
        default:
            cout << "Error: Invalid credit rating" << endl;
            return;
    }

    // We add to the array this new HighCreditAccount composed of all the user input
    m_accArr[m_accNum] = new HighCreditAccount(id, balance, name, interestRate, specialRate);
    m_accNum++;
}

// This method is usefull to enhance the prompt display when there is an error
int AccountHandler::CinIgnore(void) const{
    if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Invalid: you need to enter a number..." << endl;
            return -1;
        }
    return 0;
}