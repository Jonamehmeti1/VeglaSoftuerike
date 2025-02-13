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
    BankAccount(string accNum, string accHolder, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = accHolder;
        balance = (initialBalance >= 0) ? initialBalance : 0;
        if (initialBalance < 0) {
            cout << "Bilanci fillestar nuk mund të jetë negativ. Vendoset në $0.00" << endl;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Depozitimi u krye me sukses: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Shuma e depozitimit duhet të jetë më e madhe se zero." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Shuma e tërhequr me sukses: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Tërheqja e dështuar. Fondi i pamjaftueshëm ose shuma është e pavlefshme." << endl;
        }
    }

    void displayAccountInfo() {
        cout << "\nDetajet e Llogarisë:\n";
        cout << "Numri i Llogarisë: " << accountNumber << endl;
        cout << "Emri i Pronarit: " << accountHolderName << endl;
        cout << "Bilanci: $" << fixed << setprecision(2) << balance << endl;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    string accNum, accHolder;
    double initBalance, depositAmount, withdrawAmount;
    char choice;

    cout << "Shkruani numrin e llogarisë: ";
    cin >> accNum;
    cin.ignore();
    cout << "Shkruani emrin e pronarit të llogarisë: ";
    getline(cin, accHolder);
    cout << "Shkruani bilancin fillestar: ";
    cin >> initBalance;

    BankAccount account(accNum, accHolder, initBalance);

    account.displayAccountInfo();

    cout << "\nA dëshironi të depozitoni para? (Përgjigjuni me 'P' për PO, ose çdo tjetër për të vazhduar): ";
    cin >> choice;
    if (choice == 'P' || choice == 'p') {
        cout << "Shkruani shumën që dëshironi të depozitoni: $";
        cin >> depositAmount;
        account.deposit(depositAmount);
        account.displayAccountInfo();
    }

    cout << "\nA dëshironi të tërhiqni para? (Përgjigjuni me 'T' për PO, ose çdo tjetër për të përfunduar): ";
    cin >> choice;
    if (choice == 'T' || choice == 't') {
        cout << "Shkruani shumën që dëshironi të tërhiqni: $";
        cin >> withdrawAmount;
        account.withdraw(withdrawAmount);
        account.displayAccountInfo();
    }

    cout << "\nFaleminderit që përdorët sistemin tonë bankar!" << endl;

    return 0;
}
