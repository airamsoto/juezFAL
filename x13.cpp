#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto E37
using namespace std;

/*
 *
 * P{
 * v.size() >= 0
 * }
 * func int segmentoDeConsecutivos (const vector<int> &v) dev mayor
 *
 * Q{
 *  mayor = max (#e: 0<= e <v.size(): para todo U 0<= u <= e : abs(v[u] - v[u+1]) == 1)
 * }
 *
 * invariante: 0<= i < v.size()  ^ mayor = max (#e: 0<= e <v.size(): )
 *
 * cota: n - i
 *
 *
 */

//falta el predicado todo pares todosPares(v, p, q

int menorQueKPares (const vector<int>&v, int k) {
    int actual = 0, mayor = 0, pares = 0;
    for (int i = 0; i < v.size(); ++i) {

        if(v[i] % 2 == 0) {
            pares++;
            if(pares > k) {
                if(v[i-k] % 2 == 0) {
                    pares--;
                    actual = k;
                }
            } else actual++;
        } else {
            pares = 0;
            actual++;
        }

        mayor = max(mayor, actual);

    }
    return mayor;
}

void resuelveCaso() {
    int n, k;
    cin >> n >> k;
    int aux;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }

    cout << menorQueKPares(v, k) << '\n';




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
