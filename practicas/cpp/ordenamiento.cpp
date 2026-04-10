#include <iostream>
#include <vector>
#include <string>
using namespace std;

// BURBUJA
void burbuja(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool intercambiado = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambiado = true;
            }
        }
        if (!intercambiado) break;
    }
}

// SELECCION
void seleccion(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

// MEZCLAR
vector<int> mezclar(const vector<int>& izq, const vector<int>& der) {
    vector<int> resultado;
    int i = 0, j = 0;

    while (i < izq.size() && j < der.size()) {
        if (izq[i] <= der[j]) {
            resultado.push_back(izq[i]);
            i++;
        } else {
            resultado.push_back(der[j]);
            j++;
        }
    }

    while (i < izq.size()) {
        resultado.push_back(izq[i]);
        i++;
    }

    while (j < der.size()) {
        resultado.push_back(der[j]);
        j++;
    }

    return resultado;
}

// MERGESORT
vector<int> mergesort(const vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    int medio = arr.size() / 2;

    vector<int> izq(arr.begin(), arr.begin() + medio);
    vector<int> der(arr.begin() + medio, arr.end());

    izq = mergesort(izq);
    der = mergesort(der);

    return mezclar(izq, der);
}

// MAIN
int main() {
    string algoritmo;
    int n;

    cin >> algoritmo >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (algoritmo == "burbuja") {
        burbuja(arr);
    } else if (algoritmo == "seleccion") {
        seleccion(arr);
    } else if (algoritmo == "mergesort") {
        arr = mergesort(arr);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << " ";
    }

    return 0;
}