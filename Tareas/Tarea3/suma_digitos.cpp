#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int suma = 0;

    // Mientras el número sea mayor que 0
    while (n > 0) {
        suma += n % 10; // sacar último dígito
        n = n / 10;     // eliminar último dígito
    }

    cout << suma;

    return 0;
}