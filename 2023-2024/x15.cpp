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


int cerosYUnos(const vector<int> &v, int l) {
    int contador = 0, ceros = 0, unos = 0, k = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] == 0) ceros++;
        else if(v[i] == 1) unos++;
        k++;

        if(k == l) {
            if (ceros == unos) contador++;
            if(v[i-l+1] == 0) ceros--;
            else if(v[i-l+1] == 1) unos--;
            k--;
        }
    }
    return contador;
}



void resuelveCaso() {
    int n, l;
    cin >> l >> n;
    int aux;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }
    cout << cerosYUnos(v, l) << '\n';


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

#endif
    return 0;
}
