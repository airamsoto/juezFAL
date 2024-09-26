/*
NOMBRE Y APELLIDOS:

*/

#include <iostream>
#include <vector>

using namespace std;

// Función que encuentra el número más grande que falta en la secuencia
int perdido(const vector<int> &v, int ini, int fin) {
    if (ini + 1 == fin) {
        // Solo dos elementos, retornamos el número intermedio que falta
        return v[ini] + ((v[fin] - v[ini]) / 2) + 1;
    } else {
        int mid = (ini + fin) / 2;
        int expected_mid_value = v[ini] + (mid - ini) * ((v[fin] - v[ini]) / (fin - ini));

        if (v[mid] != expected_mid_value) {
            // El número faltante está en la primera mitad
            return perdido(v, ini, mid);
        } else {
            // El número faltante está en la segunda mitad
            return perdido(v, mid, fin);
        }
    }
}

// Función principal que resuelve el problema
int num_perdido(const vector<int> &v) {
    return perdido(v, 0, v.size() - 1);
}

bool ejecuta_caso() {
    int n;
    cin >> n;
    if (n == -1) return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << num_perdido(v) << endl;
    return true;
}

int main() {
    while (ejecuta_caso());
    return 0;
}
