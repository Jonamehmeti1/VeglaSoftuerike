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
    double initBalance, depositAmount;

    cout << "Shkruani numrin e llogarisë: ";
    cin >> accNum;
    cin.ignore();
    cout << "Shkruani emrin e pronarit të llogarisë: ";
    getline(cin, accHolder);
    cout << "Shkruani bilancin fillestar: ";
    cin >> initBalance;

    BankAccount account(accNum, accHolder, initBalance);

    account.displayAccountInfo();

    cout << "\nShkruani shumën që dëshironi të depozitoni: $";
    cin >> depositAmount;
    account.deposit(depositAmount);

    account.displayAccountInfo();

    return 0;
}
