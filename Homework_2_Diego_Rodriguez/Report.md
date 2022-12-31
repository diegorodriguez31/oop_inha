# RODRIGUEZ Diego Guilhem 12224836 - Object Oriented Programming for Homework 2
In this report, I will briefly explain what I did and how I did it.
The most interesting explanations will be in the comments you can find accross the source code.

## Exercise 1
First, I had to transform the Bank system we already made into a class system.
For that, the struct of Account became the class 'Account'.
The bank became the 'AccountManager'
The bank enumeration and constants are now stored in the file `BankCommon.h`
I converted the functions GetAccID(void) and ShowAccInfo(void) from the Account class into const functions because these functions are only reading data and never modify the object or call non const functions.

In order to do a deep copy, it was important to first allocate new memory for the cusName parameter. This parameter is an array of character and to initialise it (because it's a pointer), we need new memory allocation. Otherwise, the new object would point to the same address that the copied one for the name parameter and this is not good at all. 

```cpp
Account::Account(const Account& ref): m_accID{ref.m_accID}, m_balance{ref.m_balance} {
    int len = strlen(ref.m_cusName) + 1;
    m_cusName = new char[len];
    strcpy(m_cusName, ref.m_cusName);
};
```
I couldn't use strcpy_s() function because it didn't work well on VSCode. I'm running with Linux so I can't use MS Visual Code.Moreover, it's more safe to use only the strcpy() function. Thus, I used only this one and I didn't get any error message on VSCode.

## Exercise 2
From this exercise, I created all the class with a class definition file with the `.h` extension and with a class implementation with the `.cpp` extension.

From now, the AccountHandler use a array of Account objects thanks to an Account pointer array. Furthermore, the main program is using now the AccountHandler as a manager of accounts.

Now, the AccountHandler propose some actions to do on its accounts by the user. This manager is doing all the main prompts, creating, deleting the accounts, doing all the actions to find the good account to deal with. Then, the manager will call the desired operation on the account. It is in the class Account that the operation is actually done like for example deposit money, withdraw money or get the account information. The AccountManager pass the good parameter to the Account being treated.

## Exercise 3
Now, we want to inherit from Account to have 2 new types of account. A SavingAccount and a HighCreditAccount. So we will not use anymore the basic account but these two types of account. The idea for SavingAccount is to have an interest when we deposit money so we gain more money. The HighCreditAccount is the same kind than SavingAccount but with one more interest gain. Because we change the deposit behaviour of these two class, we need to redefine only this method for both of them.

In order to doing that, we change the deposit member function of Account virtual so that the AccountHandler class can call the most derived deposit member function at runtime. In this case, SavingAccount inherit from Account and HighCreditAccount inherit from SavingAccount.

For doing that, we just have to add the keyword "virtual" before the member function declaration in `Account.h`, `SavingAccount.h` and `HighCreditAccount.h`.

The impletentation of the deposit of SavingAccount and HighCreditAccount are respectively as follow:

```cpp
void SavingAccount::Deposit(int money) {
    Account::Deposit(money);
    Account::Deposit(money * (m_InterestRate / 100.0));
}
```

```cpp
void HighCreditAccount::Deposit(int money) {
    SavingAccount::Deposit(money);
    Account::Deposit(money * (m_SpecialRate / 100.0));
}
```

The idea is too first deposit the normal amount of a normal account. Then we deposit the interest rate for the saving account. For HighCreditAccount, we do this and we deposit then the special rate.

## Running the program
In order to run the program, you should place yourself into the directory "Implementation_files" and then run the following command:

`g++ Account.cpp AccountHandler.cpp BankMain.cpp HighCreditAccount.cpp SavingAccount.cpp -o main`

## Example of output
You will notice in the example that I added some functionalities like displaying only one account or deleting the accounts and much more.
I invite you to run the program yourself to explore more possibilities. I didn't make an example exhaustive with all the possibilities.

```bash
Implementation_files ./main

-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 1



[Select Account Type]
1. Saving Account
2. High Credit Account
Select: 1
[Make Saving Account]
Account ID: 1
Customer name: Diego
Deposit amount: 10000
Interest Rate: 10


-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 1



[Select Account Type]
1. Saving Account
2. High Credit Account
Select: 2
[Make High Credit Account]
Account ID: 2
Customer name: Kim
Deposit amount: 20000
Interest Rate: 5
Credit Rating(A:1, B:2, C:3): 1


-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 2



[Deposit]
Account ID: 1
Deposit amount: 1000
Deposit complete


-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 2



[Deposit]
Account ID: 2
Deposit amount: 1000
Deposit complete


-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 4



[Display all]
---------------------------------
Account ID: 1
Name: Diego
Balance: 11100


Account ID: 2
Name: Kim
Balance: 21120



-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 3



[Withdrawal]
Account ID: 1 
Withdrawal amount: 1000
Withdrawal complete


-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 3



[Withdrawal]
Account ID: 2
Withdrawal amount: 1000
Withdrawal complete


-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 4



[Display all]
---------------------------------
Account ID: 1
Name: Diego
Balance: 10100


Account ID: 2
Name: Kim
Balance: 20120



-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 3



[Withdrawal]
Account ID: 1
Withdrawal amount: 100000
Error: Insufficient balance

-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 5



[Account that you want to display]
1
Account ID: 1
Name: Diego
Balance: 10100


-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 7



All accounts are being deleted

Account deleted
---------------------------------
Account ID: 1
Name: Diego
Balance: 10100

Account deleted
---------------------------------
Account ID: 2
Name: Kim
Balance: 20120

Delete complete


-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 4



[Display all]
---------------------------------

-----Menu------------------------
1. Make account
2. Deposit
3. Withdrawal
4. Display all
5. Display one
6. Delete account
7. Delete all
8. Exit program
---------------------------------
Select menu: 8



➜  Implementation_files 
```