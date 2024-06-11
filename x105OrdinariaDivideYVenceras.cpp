#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto E37
using namespace std;

int picudo(const vector<int> &v, int ini, int fin) {
    if (ini == fin) {
        return 0;
    } else if (ini == fin - 1) {
        return v[fin] - v[ini];

    } else {
        int m = (ini + fin) / 2;
        int der = picudo(v, ini, m);
        int izq = picudo(v, m, fin);
        return max(der, izq);
    }
}


void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];

    }
    cout << picudo(v, 0, n-1) << '\n';
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        resuelveCaso();
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}