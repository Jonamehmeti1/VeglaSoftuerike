#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, string accHolder, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = accHolder;
        balance = (initialBalance >= 0) ? initialBalance : 0;
        if (initialBalance < 0) {
            cout << "Bilanci fillestar nuk mund të jetë negativ. Vendoset në $0.00" << endl;
        }
    }

    // Deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Depozitimi u krye me sukses: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Shuma e depozitimit duhet të jetë më e madhe se zero." << endl;
        }
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Shuma e tërhequr me sukses: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Tërheqja e dështuar. Fondi i pamjaftueshëm ose shuma është e pavlefshme." << endl;
        }
    }

    // Transfer money to another account
    void transfer(BankAccount &recipient, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transferi u krye me sukses te " << recipient.accountHolderName 
                 << " me shumën $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Transferi nuk mund të kryhet. Bilanci juaj është i pamjaftueshëm!" << endl;
        }
    }

    // Display account details
    void displayAccountInfo() {
        cout << "\nDetajet e Llogarisë:\n";
        cout << "Numri i Llogarisë: " << accountNumber << endl;
        cout << "Emri i Pronarit: " << accountHolderName << endl;
        cout << "Bilanci: $" << fixed << setprecision(2) << balance << endl;
    }

    // Getter for balance
    double getBalance() {
        return balance;
    }
};

int main() {
    string accNum1, accHolder1, accNum2, accHolder2;
    double initBalance1, initBalance2, amount;
    string choice;

    // Create first bank account
    cout << "Krijoni llogarinë e parë\n";
    cout << "Shkruani numrin e llogarisë: ";
    cin >> accNum1;
    cin.ignore();
    cout << "Shkruani emrin e pronarit të llogarisë: ";
    getline(cin, accHolder1);
    cout << "Shkruani bilancin fillestar: ";
    cin >> initBalance1;

    BankAccount account1(accNum1, accHolder1, initBalance1);

    // Create second bank account for transfers
    cout << "\nKrijoni llogarinë e dytë (për transferime)\n";
    cout << "Shkruani numrin e llogarisë: ";
    cin >> accNum2;
    cin.ignore();
    cout << "Shkruani emrin e pronarit të llogarisë: ";
    getline(cin, accHolder2);
    cout << "Shkruani bilancin fillestar: ";
    cin >> initBalance2;

    BankAccount account2(accNum2, accHolder2, initBalance2);

    // Display initial account details
    account1.displayAccountInfo();
    account2.displayAccountInfo();

    // Deposit Money
    cout << "\nA dëshironi të depozitoni para në llogarinë e parë? (P - PO, ndryshe JO): ";
    cin >> choice;
    if (choice == "P" || choice == "p") {
        cout << "Shkruani shumën: $";
        cin >> amount;
        account1.deposit(amount);
        account1.displayAccountInfo();
    }

    // Withdraw Money
    cout << "\nA dëshironi të tërhiqni para nga llogaria e parë? (T - PO, ndryshe JO): ";
    cin >> choice;
    if (choice == "T" || choice == "t") {
        cout << "Shkruani shumën: $";
        cin >> amount;
        account1.withdraw(amount);
        account1.displayAccountInfo();
    }

    // Transfer Money
    cout << "\nA dëshironi të transferoni para nga llogaria e parë te llogaria e dytë? (Tr - PO, ndryshe JO): ";
    cin >> choice;
    if (choice == "Tr" || choice == "tr") {  // FIXED: Correctly checking for 'Tr'
        cout << "Shkruani shumën për transferim: $";
        cin >> amount;
        account1.transfer(account2, amount);
        account1.displayAccountInfo();
        account2.displayAccountInfo();
    }

    cout << "\nFaleminderit që përdorët sistemin tonë bankar!" << endl;
    return 0;
}
