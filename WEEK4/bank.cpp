#include <iostream>
#include <cstring>
#include "bank.h"
using namespace std;

Account accArr[MAX_ACC_NUM]; // Account array
int accNum = 0; // number of accounts

void ShowMenu(void)
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

void MakeAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;

    if (accNum >= MAX_ACC_NUM) {
        cout << "Account number is full, cannot make an account anymore" << endl;
        return;
    }

    cout << "[Make account]" << endl;
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
    cout << endl;

    if (GetAccIdx(id) != -1){
        cout << "Error: Account ID already exists" << endl;
        return;
    }

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void DepositMoney(void) {
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

    accArr[idx].balance += money;
    cout << "Deposit complete" << endl << endl;
}

void WithdrawMoney(void) {
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

    if (accArr[idx].balance < money) {
        cout << "Error: Insufficient balance" << endl;
        return;
    }

    accArr[idx].balance -= money;
    cout << "Withdrawal complete" << endl << endl;
}

void ShowAllAccInfo(void) {
    for (int i = 0; i < accNum; i++) {
        cout << "Account ID: " << accArr[i].accID << endl;
        cout << "Customer name: " << accArr[i].cusName << endl;
        cout << "Balance: " << accArr[i].balance << endl << endl;
    }
}

void ShowAccInfo(void) {
    int id;
    cout << "[Account that you want to display]" << endl;
    cout << "Account ID: ";
    cin >> id;

    int idx = GetAccIdx(id);
    if (idx == -1) {
        cout << "Error: Account ID does not exist" << endl;
        return;
    }

    cout << "Customer name: " << accArr[idx].cusName << endl;
    cout << "Balance: " << accArr[idx].balance << endl << endl;
}

int GetAccIdx(int id) {
    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id)
            return i;
    }
    return -1;
}

void DeleteAccount(void) {
    int id;
    cout << "[Delete account]" << endl;
    cout << "Account ID: ";
    cin >> id;
    if (CinIgnore() == -1) {
        return;
    }

    int idx = GetAccIdx(id);
    if (idx == -1) {
        cout << "Error: Account ID does not exist" << endl;
        return;
    }

    cout << "Account is being deleted" << endl;
    cout << "Id: " << id << endl;
    cout << "Name: " << accArr[idx].cusName << endl;
    cout << "The deposit of the account was: " << accArr[idx].balance << endl;

    for (int i = idx; i < accNum - 1; i++) {
        accArr[i] = accArr[i + 1];
    }
    accNum--;
    cout << "Delete complete" << endl << endl;
}

void DeleteAllAccounts(void) {
    cout << "All accounts are being deleted" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < accNum; i++) {
        cout << "Id: " << accArr[i].accID << endl;
        cout << "Name: " << accArr[i].cusName << endl;
        cout << "The deposit of the account was: " << accArr[i].balance << endl;
    }
    accNum = 0;
    cout << "---------------------------------" << endl;
    cout << "Delete complete" << endl << endl;
}

int CinIgnore(void) {
    if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Invalid: you need to enter a number..." << endl;
            return -1;
        }
    return 0;
}