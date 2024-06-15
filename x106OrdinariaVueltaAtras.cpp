#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

bool puedeCogerla(int necesaria, const vector<bool> &aprobadas) {
    if (necesaria == -1) return true;
    return aprobadas[necesaria];
}

void creditosAsignaturas(const vector<bool> &aprobadas, const vector<int> &prerequisitos, const vector<int> &creditosV,
                         const vector<int> &coste, vector<bool> &escogidas, int contadorDeCreditos, int costeActual,
                         int &mejorCoste, const vector<int> &orden, int k, int cred) {

    if (contadorDeCreditos >= cred) {
        if (costeActual < mejorCoste) {
            mejorCoste = costeActual;
        }
        return;
    }

    if (k == orden.size()) {
        return;
    }

    int i = orden[k];
    if (!escogidas[i] && puedeCogerla(prerequisitos[i], aprobadas) && !aprobadas[i]) {
        escogidas[i] = true;
        costeActual += coste[i];
        contadorDeCreditos += creditosV[i];
        creditosAsignaturas(aprobadas, prerequisitos, creditosV, coste, escogidas, contadorDeCreditos, costeActual, mejorCoste, orden, k + 1, cred);
        escogidas[i] = false;
        costeActual -= coste[i];
        contadorDeCreditos -= creditosV[i];
    }

    creditosAsignaturas(aprobadas, prerequisitos, creditosV, coste, escogidas, contadorDeCreditos, costeActual, mejorCoste, orden, k + 1, cred);
}

void resuelveCaso() {
    int asignaturas, creditos;
    cin >> asignaturas >> creditos;

    vector<bool> aprobadas(asignaturas);
    vector<int> prerequisitos(asignaturas);
    vector<int> creditosV(asignaturas);
    vector<int> coste(asignaturas);

    char aux;
    for (int i = 0; i < asignaturas; ++i) {
        cin >> aux;
        aprobadas[i] = (aux == 'A');
    }

    for (int i = 0; i < asignaturas; ++i) {
        cin >> prerequisitos[i];
    }

    for (int i = 0; i < asignaturas; ++i) {
        cin >> creditosV[i];
    }

    for (int i = 0; i < asignaturas; ++i) {
        cin >> coste[i];
    }


    vector<int> orden(asignaturas);
    for (int i = 0; i < asignaturas; ++i) {
        orden[i] = i;
    }

    sort(orden.begin(), orden.end(), [&](int a, int b) {
        return (double)creditosV[a] / coste[a] > (double)creditosV[b] / coste[b];
    });

    int contadorDeCreditos = 0, costeActual = 0, mejorCoste = INT_MAX;
    vector<bool> escogidas(asignaturas, false);
    creditosAsignaturas(aprobadas, prerequisitos, creditosV, coste, escogidas, contadorDeCreditos, costeActual, mejorCoste, orden, 0, creditos);

    if (mejorCoste == INT_MAX) {
        cout << "NO" << '\n';
    } else {
        cout << mejorCoste << '\n';
    }
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
