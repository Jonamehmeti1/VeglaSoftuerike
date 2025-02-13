#include <iostream>
#include <iomanip>  

using namespace std;

class BankAccount {
private:
    double balance;

public:
    // Per inicializim te bilancit
    BankAccount(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            cout << "Bilanci inicial nuk mund të jetë negativ." << endl;
            balance = 0;
        }
    }

    // Per depozitim
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Keni depozituar me sukses: $" << fixed << setprecision(2) << amount << endl;
            cout << "Bilanci aktual: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Shuma duhet të jetë më e madhe se zero." << endl;
        }
    }

    // Metoda qe e kthen bilancin
    double getBalance() {
        return balance;
    }
};

int main() {
    double initialBalance = 1000.00;  // Bilanci fillestar ne llogari
    BankAccount account(initialBalance);

    cout << "Mirësevini në Bankë!" << endl;
    cout << "Bilanci juaj aktual: $" << fixed << setprecision(2) << account.getBalance() << endl;

    
    double depositAmount;
    cout << "Shkruani shumën që dëshironi të depozitoni: $";
    cin >> depositAmount;

    //Thirrja e metodes deposit
    account.deposit(depositAmount);

    return 0;
}
