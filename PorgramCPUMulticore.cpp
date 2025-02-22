#include <iostream>
#include <vector>
#include <omp.h>

#define N 1000000  // Número de transacciones

using namespace std;

void detectFraud(vector<double> &transactions, vector<bool> &fraudFlags) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (transactions[i] > 10000) {  // Ejemplo: si la transacción es >$10,000 se marca como sospechosa
            fraudFlags[i] = true;
        }
    }
}

int main() {
    vector<double> transactions(N, 5000.0);
    vector<bool> fraudFlags(N, false);

    transactions[12345] = 15000;  // Simulamos una transacción sospechosa

    detectFraud(transactions, fraudFlags);
    cout << "Detección de fraude." << endl;

    return 0;
}
