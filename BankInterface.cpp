#include <iostream>
#include <string>

using namespace std;

// Funksioni qe kryen transferimin e parave
void transferoPara(double &bilanci) {
    string llogaria;
    double shuma;

    // Marrja e të dhënave nga përdoruesi
    cout << "Shkruani emrin e llogarise ku doni te transferoni parate: ";
    cin.ignore();  // Pastron buferin per te lejuar getline te funksionoje pas cin
    getline(cin, llogaria);

    cout << "Shkruani shumen qe doni te transferoni: ";
    cin >> shuma;

    // Kontrolli i bilancit
    if (shuma > bilanci) {
        cout << "Transferi nuk mund te kryhet. Bilanci juaj eshte i pamjaftueshem!" << endl;
    } else {
        bilanci -= shuma;
        cout << "Transferi u krye me sukses ne xhirollogarine \"" << llogaria << "\"." << endl;
        cout << "Bilanci juaj i mbetur eshte: " << bilanci << " EURO." << endl;
    }
}

int main() {
    double bilanci = 1000.00; // Bilanci fillestar i klientit

    // Thirrja e funksionit per te bere transferin
    transferoPara(bilanci);

    return 0;
}