#include <iostream>
#include <string>
using namespace std;

struct BankAccount {
    string accountNumber;
    string accountHolderName;
    double balance;
};

void createAccount(BankAccount &account, const string &accNum, const string &accHolder, double initBalance) {
    account.accountNumber = accNum;
    account.accountHolderName = accHolder;
    account.balance = initBalance;
    cout << "Account created successfully!" << endl;
}

int main() {
    BankAccount myAccount;
    string accNum, accHolder;
    double initBalance;

    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter account holder name: ";
    cin.ignore(); 
    getline(cin, accHolder);
    cout << "Enter initial balance: ";
    cin >> initBalance;

    createAccount(myAccount, accNum, accHolder, initBalance);

    cout << "\nAccount Details:\n";
    cout << "Account Number: " << myAccount.accountNumber << endl;
    cout << "Account Holder: " << myAccount.accountHolderName << endl;
    cout << "Balance: $" << myAccount.balance << endl;

    return 0;
}
