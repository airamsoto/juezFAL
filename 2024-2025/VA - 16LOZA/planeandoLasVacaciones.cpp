#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void vacaciones(const vector<vector<int>> &datos, int k, int n, int &costeActual, int &mejorCoste, vector<bool> &marcador, vector<int> &solucionActual, vector<int> &mejorSolucion) {
    for (int i = 1; i < n; i++) {
        if (!marcador[i]) {
            marcador[i] = true;
            solucionActual[k] = i;
            costeActual += datos[solucionActual[k-1]][i];
            if (k == n - 1) {
                int total = costeActual + datos[solucionActual[k-1]][0];
                if (total < mejorCoste) {
                    mejorCoste = total;
                    mejorSolucion = solucionActual;
                }
            } else {
                vacaciones(datos, k + 1, n, costeActual, mejorCoste, marcador, solucionActual, mejorSolucion);
            }
            marcador[i] = false;
            costeActual -= datos[solucionActual[k-1]][i];
        }
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0) return false;

    vector<vector<int>> datos(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> datos[i][j];
            
        }
    }

    vector<bool> marcador(n, false);
    marcador[0] = true;
    int costeActual = 0, mejorCoste = INT_MAX;
    vector<int> solucionActual(n), mejorSolucion(n);
    solucionActual[0] = 0;

    vacaciones(datos, 1, n, costeActual, mejorCoste, marcador, solucionActual, mejorSolucion);
    
    cout << mejorCoste << endl;

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
