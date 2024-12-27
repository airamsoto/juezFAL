#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>
using namespace std;

bool esPosible(const vector<int>& v, int p, int maxTiempo) {
    int paradas = 0;
    int tiempoAcumulado = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > maxTiempo) return false;
        if (tiempoAcumulado + v[i] > maxTiempo) {
            paradas++;
            tiempoAcumulado = v[i];
            if (paradas > p) return false;
        } else {
            tiempoAcumulado += v[i];
        }
    }
    return true;
}

bool resuelveCaso() {
    int n, p;
    cin >> n >> p;
    if (n == 0 && p == 0) return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int bajo = 1, alto = accumulate(v.begin(), v.end(), 0);
    while (bajo < alto) {
        int medio = (bajo + alto) / 2;
        if (esPosible(v, p, medio)) {
            alto = medio;
        } else {
            bajo = medio + 1;
        }
    }

    cout << bajo << endl;
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
