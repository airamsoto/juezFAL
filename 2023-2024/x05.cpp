#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto E37
using namespace std;

/* Coste: este algoritmo presenta un coste 0(n) lineal siendo n el numero de elementos del vector
 * n = v.size()
 * P{ n > 0 ^ p <= n}
 *estaBienDividido (const vector<int> &v, int p) dev bool b
 * Q { Ve( mayorNumero = max(v[e])), 0 < e < p) ^ bool b = true sii Vu : p < u < v.size() (mayorNumero > v[u])
 *
 * Invariante: 0<= i<= p, Ve( mayorNumero = max(v[e])), 0 < e < p)
 *
 *
 * Funcion cota: n - i -j
 *
 */


bool estaBienDividido (const vector<int> &v, int p) {
    int i = 0, mayorNumero = INT_MIN;

    while (i <= p && i < v.size()) {
        mayorNumero = max(mayorNumero, v[i]);
        i++;
    }
    bool ok = true;
    int j = i;
    while (ok && j < v.size()) {
        if(v[j] <= mayorNumero) ok = false;
        j++;
    }
    return ok;
}


void resuelveCaso () {
    int n, p;
    cin >> n >> p;

    vector <int> v;
    int aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }

    if(estaBienDividido(v, p)) cout << "SI" << '\n';
    else cout << "NO" << '\n';




}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}