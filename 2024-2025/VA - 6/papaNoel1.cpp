#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool esValida(const vector<pair<string, int>>& sol, const string& juguete, int k) {
    if (k % 2 == 1) {
        if (sol[k-1].first >= juguete) return false;
    }
    return true;
}
void imprimirSolucion(const vector<pair<string, int>>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i].second << " ";
    }
    cout << '\n';
}

void juguetesNavidad(vector<pair<string, int>>& sol, const vector<string>& juguetes, int k, bool& haySolucion) {

    for (int i = 0; i < juguetes.size(); ++i) {
        if (esValida(sol, juguetes[i], k)) {
            sol[k] = {juguetes[i], i};
            if (k == sol.size() - 1) {
                imprimirSolucion(sol);
                haySolucion = true;
            } else
            juguetesNavidad(sol, juguetes, k+1, haySolucion);
        }
    }
}

bool resuelveCaso() {
    int m, n;
    cin >> m >> n;
    if (!cin) return false;

    vector<string> juguetes(m);
    for (int i = 0; i < m; i++) {
        cin >> juguetes[i];
    }

    vector<pair<string, int>> sol(n * 2);
    bool haySol = false;
    juguetesNavidad(sol, juguetes, 0, haySol);

    if (!haySol) {
        cout << "SIN SOLUCION\n";
    }

    cout << '\n';
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
