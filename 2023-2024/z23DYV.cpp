/*
NOMBRE Y APELLIDOS:

*/

#include <iostream>
#include <climits> // Para INT_MAX y INT_MIN

using namespace std;
bool hay_nifunifa(int v[], int ini, int fin) {
    if (fin - ini <= 1) {
        return false;
    }

    int mid = (ini + fin) / 2;
    if (v[ini] != v[mid] && v[mid] != v[fin] && (v[ini] != v[fin])) {
        return true;
    }
    bool izq = hay_nifunifa(v, ini, mid);
    bool der = hay_nifunifa(v, mid, fin);

    return izq || der;
}

const static int MAX_ELEMS = 1000000;

bool ejecuta_caso() {
    static int a[MAX_ELEMS];
    int n;
    cin >> n;
    if (n == -1) return false;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (hay_nifunifa(a, 0, n - 1)) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }

    return true;
}

int main() {
    while (ejecuta_caso());
    return 0;
}
