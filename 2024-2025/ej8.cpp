
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto
using namespace std;


bool resuelveCaso() {
    int p, u, n, aux, k, total = 0;
    cin >> p >> u;
    if (p == 0 && u == 0) return false;

    n = u - p + 1;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v[i] = aux;
        if (i > 0) v[i] += v[i - 1];
    }
    cin >> k;
    int nP, nU;
    for (int i = 0; i < k; ++i) {
        cin >> nP >> nU;
        if (nP == p) {
            total = v[nU - p];
        } else {
            total = v[nU - p] - v[nP - p - 1];
        }
        cout << total << '\n';
    }

    cout << "---" << '\n';
    return true;

}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso()){}

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}