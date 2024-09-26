#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto E37
using namespace std;

/*
 * Coste: coste 0(n) siendo n el numero de elementos del vector
 * P{
 *  v.size() >=0 ^ desnivel >= 0
 * }
 * func esApta (const vector<int> &v, int desnivel) dev bool b
 * Q{
 *
 *  b true sii para todo e: 1<= e <= v.size(): Existe u: 1< u < e: (Sumatorio  v[u-1]- v[u] <= desnivel)
 *
 * }
 *
 * Invariante: 1 <= i <= v.size() ^ para todo e: 1<= i <= v.size(): Existe u: 1 < u < i: (Sumatorio  v[u-1]- v[u] <= desnivel)
 *
 *
 * Funcion cota: n - i
 *
 */

bool esApta (const vector<int> &v, int desnivel) {
    int acum = 0, i = 1;
    bool apta = true;
    while (i < v.size() && apta) {
        int prev = v[i-1];
        int act = v[i] - prev;
        if(act > 0) acum+= act;
        else acum = 0;
        if(acum > desnivel) apta = false;
        i++;
    }
    return apta;
}




bool resuelveCaso() {
    int desnivel, n, aux;
     cin >> desnivel >> n;
     if(!cin) return false;
    vector<int> alturas;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        alturas.push_back(aux);
    }

    if(esApta(alturas, desnivel)) cout << "APTA" << '\n';
    else cout << "NO APTA" << '\n';





    return true;


}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}