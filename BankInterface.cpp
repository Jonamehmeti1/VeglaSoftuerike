#include <iostream>
#include <iomanip>

using namespace std;

void terheqShumeParash(double &totali) {
    string pergjigje;
    double shuma;

    while (true) {
        cout << "A deshironi te terhiqni nje shume parash? (PO/JO): ";
        cin >> pergjigje;

        if (pergjigje == "PO" || pergjigje == "po") {
            cout << "Shkruani shumen qe deshironi te terhiqni: ";
            cin >> shuma;

            if (shuma <= totali) {
                totali -= shuma;
                cout << "Shuma e terhequr me sukses. Totali i mbetur: " << totali << endl;
                break;
            } else {
                cout << "Fondi nuk eshte i mjaftueshem. Ju lutem provoni perseri." << endl;
            }
        } else if (pergjigje == "JO" || pergjigje == "jo") {
            break;
        } else {
            cout << "Pergjigje e pavlefshme. Ju lutem provoni perseri." << endl;
        }
    }
}

int main() {
    double totali = 1000.0; 

    terheqShumeParash(totali);

    cout << "Programi vazhdon..." << endl;

    return 0;
}