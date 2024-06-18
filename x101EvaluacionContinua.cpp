#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto E37
using namespace std;

/*
 *
 * P{
 *
 * }
 *
 *
 * Q{
 *
 * }
 *
 * invariante:
 *
 * cota:
 *
 *
 */

//falta el predicado todo pares todosPares(v, p, q)


int segmentosDeImpares (const vector<int>& v, int k, int l) {
    int contador = 0, impares = 0, r = 0;
    for (int i = 0; i < v.size(); ++i) {
        contador++;
        if (v[i] % 2 != 0) impares++;
        if(contador == k) {
            if(impares <= l) r++;
            if(v[i-k+1] % 2 != 0) impares--;
            contador--;
        }

    }

    return r;
    
}



void resuelveCaso() {
    int n, l, k;
    cin >> n >> k >> l;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];

    }

    if (k == 0) cout << n +1 << '\n';
    else cout << segmentosDeImpares (v,k,l) << '\n';


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
    //system("pause");
#endif
    return 0;
}
