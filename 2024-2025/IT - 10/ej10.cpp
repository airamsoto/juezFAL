
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto
using namespace std;

/*
 * x < y
 * x impar
 * y par
 */

int impares(const vector<int> &v) {
    int contador = 0, impares = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] % 2 != 0) {
            impares++;
        } else {
            contador += impares;
        }
    }
    return contador;
}


void resuelveCaso() {
    int n, aux;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v[i] = aux;
    }
    cout << impares(v) << '\n';

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
#endif
    return 0;
}