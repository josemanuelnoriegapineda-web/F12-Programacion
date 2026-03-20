#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Caso especial
    if (n == 2) {
        cout << "primo";
        return 0;
    }

    // Si es par y mayor que 2 → no primo
    if (n % 2 == 0) {
        cout << "no primo";
        return 0;
    }

    // Verificar desde 3 hasta sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            cout << "no primo";
            return 0;
        }
    }

    cout << "primo";

    return 0;
}