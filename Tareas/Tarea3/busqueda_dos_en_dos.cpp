#include <iostream>
#include <vector>
using namespace std;

int busqueda_dos_en_dos(const vector<int>& lista, int n, int objetivo) {
    int i = 0;

    while (i < n && lista[i] < objetivo) {
        i += 2;
    }

    i = i - 1;

    int inicio = max(0, i);
    int fin = min(i + 1, n - 1);

    for (int j = inicio; j <= fin; j++) {
        if (lista[j] == objetivo) {
            return j;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> lista(n);

    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }

    int objetivo;
    cin >> objetivo;

    cout << busqueda_dos_en_dos(lista, n, objetivo);

    return 0;
}